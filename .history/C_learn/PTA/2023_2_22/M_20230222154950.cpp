#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
    BstNode() :
        data(0), left(NULL), right(NULL){};
    BstNode(int data) :
        data(data), left(NULL), right(NULL){};
};
BstNode *Insert(BstNode *root, int data) {
    if (root == NULL)
        root = new BstNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}
BstNode *Find1(BstNode *root, int data) {
    if (root == NULL) return NULL;
    if (root->data == data)
        return root;
    else if (root->data < data)
        return Find1(root->right, data);
    else
        return Find1(root->left, data);
}
int main() {
    BstNode *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        root = Insert(root, num);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a;
        string str;
        cin >> str;
        if (str == "is") {
            cin >> str;
            cin >> str;
            if (str == "root") {
                if (root->data == a)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            } else if (str == "parent") {
                cin >> str;
                cin >> str >> b;
            } else if (str == "left") {
                cin >> str;
                cin >> str >> b;
                BstNode *now = Find1(root, b);
                if (now->left->data == a)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            } else if (str == "right") {
                cin >> str;
                cin >> str >> b;
                BstNode *now = Find1(root, b);
                if (now->right->data == a)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
    }
}