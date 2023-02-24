/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* Prev(vector<int>& nums , int left , int right){
        if(left > right) return NULL;
        int best = left;
        for(int i = left + 1 ; i <= right;i++){
            if(nums[i] > nums[best]) best = i;
        }
        TreeNode* root = new TreeNode(nums[best]);
        root->left = Prev(nums , left , best - 1);
        root->right = Prev(nums ,   best + 1 , right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Prev(nums , 0 , nums.size() - 1);
    }
};
// @lc code=end

