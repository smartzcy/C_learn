#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct BstNode {
    int data, deep;
    BstNode *left;
    BstNode *right;
    BstNode() :
        data(0), deep(0), left(NULL), right(NULL){};
    BstNode(int data, int deep) :
        data(data), deep(deep), left(NULL), right(NULL){};
};
BstNode *Insert(BstNode *root, int data, int deep) {
    if (root == NULL)
        root = new BstNode(data, deep);
    else if (data <= root->data)
        root->left = Insert(root->left, data, deep + 1);
    else
        root->right = Insert(root->right, data, deep + 1);
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
BstNode *Find1(BstNode *root, int data) {
    if (root == NULL) return NULL;
    if (root->data == data)
        return root;
    else if (root->data < data)
        if (root->right != NULL && root->right->data == data)
            return root;
        else
            return Find1(root->right, data);
    else if (root->left != NULL && root->left->data == data)
        return root;
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
        root = Insert(root, num, 0);
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
                cin >> str >> b;
                BstNode *now = Find1(root, a);
                if (now->left != NULL && now->left->data == b || now->right != NULL && now->right->data == b)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            } else if (str == "left") {
                cin >> str;
                cin >> str >> b;
                BstNode *now = Find1(root, b);
                if (now->left != NULL && now->left->data == a)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            } else if (str == "right") {
                cin >> str;
                cin >> str >> b;
                BstNode *now = Find1(root, b);
                if (now->right != NULL && now->right->data == a)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        } else {
            cin >> b;
            cin >> str;
            cin >> str;
            if (str == "on") {
                cin >> str;
                cin >> str;
                cin >> str;
                BstNode *ad = Find1(root, a);
                BstNode *bd = Find1(root, b);
                if (ad->deep == bd->deep)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            } else {
            }
        }
    }
}