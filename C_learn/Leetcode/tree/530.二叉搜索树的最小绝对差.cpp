/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    vector<int>vec;
    void Prev(TreeNode* root){
        if(root == NULL) return ;
        Prev(root->left);
        vec.push_back(root->val);
        Prev(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        Prev(root);
        int min = INT_MAX;
        for(auto i : vec){
            for(auto j : vec){
                if(i != j){
                    if(min > abs(i - j)) min = abs(i - j);
                }
            }
        }
        return min;
        // if(root == NULL) return INT_MAX;
        // int x = INT_MAX , y = INT_MAX;
        // if(root->left != NULL) x = abs(root->val - root->left->val);
        // if(root->right != NULL) y = abs(root->val - root->right->val);
        // return min(x , min(y,min(getMinimumDifference(root->left),getMinimumDifference(root->right))));
    }
};
// @lc code=end

