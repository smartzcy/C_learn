// #include <iostream>
// #include <stack>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;
// struct BstNode {
//     int data, deep;
//     BstNode *left;
//     BstNode *right;
//     BstNode() :
//         data(0), deep(0), left(NULL), right(NULL){};
//     BstNode(int data, int deep) :
//         data(data), deep(deep), left(NULL), right(NULL){};
// };
// BstNode *Insert(BstNode *root, int data, int deep) {
//     if (root == NULL)
//         root = new BstNode(data, deep);
//     else if (data <= root->data)
//         root->left = Insert(root->left, data, deep + 1);
//     else
//         root->right = Insert(root->right, data, deep + 1);
//     return root;
// }
// BstNode *Find1(BstNode *root, int data) {
//     if (root == NULL) return NULL;
//     if (root->data == data)
//         return root;
//     else if (root->data < data)
//         return Find1(root->right, data);
//     else
//         return Find1(root->left, data);
// }
// BstNode *Find2(BstNode *root, int data) {
//     if (root == NULL)
//         return NULL;
//     else if (root->data < data) {
//         if (root->right != NULL && root->right->data == data)
//             return root;
//         else
//             return Find1(root->right, data);
//     } else {
//         if (root->left != NULL && root->left->data == data)
//             return root;
//         else
//             return Find1(root->left, data);
//     }
// }
// int main() {
//     BstNode *root = NULL;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int num;
//         cin >> num;
//         root = Insert(root, num, 0);
//     }
//     int Q;
//     cin >> Q;
//     while (Q--) {
//         int a, b;
//         cin >> a;
//         string str;
//         cin >> str;
//         if (str == "is") {
//             cin >> str;
//             cin >> str;
//             if (str == "root") {
//                 if (root != NULL && root->data == a)
//                     cout << "Yes" << endl;
//                 else
//                     cout << "No" << endl;
//             } else if (str == "parent") {
//                 cin >> str >> b;
//                 BstNode *now = Find1(root, a);
//                 if (now->left != NULL && now->left->data == b || now->right != NULL && now->right->data == b)
//                     cout << "Yes" << endl;
//                 else
//                     cout << "No" << endl;
//             } else if (str == "left") {
//                 cin >> str;
//                 cin >> str >> b;
//                 BstNode *now = Find1(root, b);
//                 if (now != NULL && now->left != NULL && now->left->data == a)
//                     cout << "Yes" << endl;
//                 else
//                     cout << "No" << endl;
//             } else if (str == "right") {
//                 cin >> str;
//                 cin >> str >> b;
//                 BstNode *now = Find1(root, b);
//                 if (now != NULL && now->right != NULL && now->right->data == a)
//                     cout << "Yes" << endl;
//                 else
//                     cout << "No" << endl;
//             }
//         } else {
//             cin >> b;
//             cin >> str;
//             cin >> str;
//             if (str == "on") {
//                 cin >> str;
//                 cin >> str;
//                 cin >> str;
//                 BstNode *ad = Find1(root, a);
//                 BstNode *bd = Find1(root, b);
//                 if (ad != NULL && bd != NULL && ad->deep == bd->deep)
//                     cout << "Yes" << endl;
//                 else
//                     cout << "No" << endl;
//             } else {
//                 BstNode *ad = Find2(root, a);
//                 BstNode *bd = Find2(root, b);
//                 if (ad != NULL && bd != NULL && ad->data == bd->data)
//                     cout << "Yes" << endl;
//                 else
//                     cout << "No" << endl;
//             }
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
typedef struct TNode {
    int data;
    struct TNode *right;
    struct TNode *left;
} *BinTree;
BinTree bst = NULL;
struct point {
    int fa, d = -1;
};
map<int, point> p;
BinTree insert(BinTree &bst, int x, int fa, int dept) {
    if (!bst) {
        bst = new TNode();
        bst->data = x;
        bst->left = bst->right = NULL;
        if (fa != -1) {
            p[x].d = dept;
            p[x].fa = fa;
        }
    } else {
        if (x < bst->data) {
            bst->left = insert(bst->left, x, bst->data, dept + 1);
        } else if (x > bst->data) {
            bst->right = insert(bst->right, x, bst->data, dept + 1);
        }
    }
    return bst;
}

int main() {
    int n, m, x, root;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(bst, x, -1, 0);
    }
    root = bst->data;
    p[root].fa = -1;
    p[root].d = 0;
    cin >> m;
    getchar();
    while (m--) {
        int x, y = -1, flag = 0;
        string s;
        getline(cin, s);
        if (s.find("root") != string::npos) {
            sscanf(s.c_str(), "%d is the root", &x);
            if (root == x) flag = 1;
        } else if (s.find("siblings") != string::npos) {
            sscanf(s.c_str(), "%d and %d are siblings", &x, &y);
            if (p[x].fa == p[y].fa) flag = 1;
        } else if (s.find("parent") != string::npos) {
            sscanf(s.c_str(), "%d is the parent of %d", &x, &y);
            if (p[y].fa == x) flag = 1;
        } else if (s.find("left") != string::npos) {
            sscanf(s.c_str(), "%d is the left child of %d", &x, &y);
            if (p[x].fa == y && x < y) flag = 1;
        } else if (s.find("right") != string::npos) {
            sscanf(s.c_str(), "%d is the right child of %d", &x, &y);
            if (p[x].fa == y && x > y) flag = 1;
        } else if (s.find("same") != string::npos) {
            sscanf(s.c_str(), "%d and %d are on the same level", &x, &y);
            if (p[x].d == p[y].d) flag = 1;
        }
        if (p[x].d == -1 || p[y].d == -1 && y != -1) flag = 0;
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
