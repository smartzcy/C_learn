/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int max_val = 0 , max_deep = 0;
    void Prev(TreeNode* root , int level){
        if(root == NULL) return;
        if(level >= max_deep){
            max_val = root->val;
            max_deep = level + 1;
        }
        Prev(root->left , level + 1);
        Prev(root->right , level + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        max_val = root->val;
        Prev(root,0);
        return max_val;
    }
};
// @lc code=end

