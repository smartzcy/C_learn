/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
#include<string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    string s1;
    void Prev(TreeNode* root){
        if(root == NULL) return;
        s1 += "(";
        s1 += to_string(root->val);
        if(root->left == NULL && root->right != NULL) s1 += "()";
        Prev(root->left);
        Prev(root->right);
        s1 += ")";
    }
    string tree2str(TreeNode* root) {
        s1 += to_string(root->val);
        if(root->left == NULL && root->right != NULL) s1 += "()";
        Prev(root->left);
        Prev(root->right);
        return s1;
    }
};
// @lc code=end

