/*
 * @lc app=leetcode.cn id=979 lang=cpp
 *
 * [979] 在二叉树中分配硬币
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
    int ans = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        ans += abs(L) + abs(R);
        return root->val + L + R - 1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

