/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    vector<int> vec;
    void Find(TreeNode* root){
        if(root == NULL) return;
        vec.push_back(root->val);
        if(root->right != NULL) Find(root->right);
        else if(root->left != NULL) Find(root->left);
        else return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        Find(root);
        return vec;
    }
};
// @lc code=end

