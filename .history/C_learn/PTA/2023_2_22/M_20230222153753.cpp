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
int main() {
    BstNode *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        root = Insert(root, num);
    }
}