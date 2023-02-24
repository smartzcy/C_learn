/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* Insert(vector<int>& nums , int left , int right){
        if(left > right) return NULL;
        int m = (left + right) / 2;
        TreeNode* temp = new TreeNode(nums[m]);
        temp->left = Insert(nums,left,m - 1);
        temp->right = Insert(nums,m + 1, right);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Insert(nums,0,nums.size() - 1);
    }
};
// @lc code=end

