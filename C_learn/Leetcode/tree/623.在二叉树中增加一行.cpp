/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL) return NULL;
        if(depth == 1){
            TreeNode* temp = new TreeNode(val , root , NULL);
            return temp;
        }
        if(depth == 2){
            TreeNode* left = new TreeNode(val , root->left , NULL);
            TreeNode* right = new TreeNode(val , NULL , root->right);
            root->left = left;
            root->right = right;
            return root;
        }
        addOneRow(root->left,val,depth - 1);
        addOneRow(root->right,val,depth - 1);
        return root;
    }
};
// @lc code=end

