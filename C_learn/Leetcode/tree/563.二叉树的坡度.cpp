/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
#include<algorithm>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    int ans = 0;
    int Prev(TreeNode* root){
        if(root == NULL) return 0;
        int L = Prev(root->left);
        int R = Prev(root->right);
        ans += abs(L - R);
        return L + R + root->val;
    }
    int findTilt(TreeNode* root) {
        Prev(root);
        return ans;
    }
};
// @lc code=end

