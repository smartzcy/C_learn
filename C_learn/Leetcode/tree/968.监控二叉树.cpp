/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    int count = 0;
    int helper(TreeNode* root){
        if(root == NULL) return 1;
        if(root->left == NULL && root->right == NULL) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        if(left == 0 || right == 0) {
            count++;
            return 2;
        }
        if(left == 2 || right == 2) return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int val = helper(root);
        if(val == 0) count += 1;
        return count;
    }
};
// @lc code=end

