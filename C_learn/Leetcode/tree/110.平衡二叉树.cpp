/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    TreeNode(int x) : val(x) , left(NULL) , right(NULL) {}
};
class Solution {
public:
    int FindHeight(TreeNode* root){
        if(root = NULL) return 0;
        return max(FindHeight(root->left) , FindHeight(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(FindHeight(root->left) - FindHeight(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end
// class Solution {
// public:
//     int height(TreeNode* root) {
//         if (root == NULL) {
//             return 0;
//         } else {
//             return max(height(root->left), height(root->right)) + 1;
//         }
//     }
//     bool isBalanced(TreeNode* root) {
//         if (root == NULL) {
//             return true;
//         } else {
//             return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
//         }
//     }
// };
