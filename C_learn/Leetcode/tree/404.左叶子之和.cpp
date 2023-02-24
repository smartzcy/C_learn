/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
#include<string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    int count = 0;
    void Prev(TreeNode* root){
        if(root == NULL) return ;
        if(root->left != NULL && root->left->left == NULL) count += root->left->val;
        Prev(root->left);
        Prev(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        Prev(root);
        return count;
    }
};
// @lc code=end

