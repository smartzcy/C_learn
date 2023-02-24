/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    vector<int>vec;
    void Prev(TreeNode* root){
        if(root == NULL) return ;
        vec.push_back(root->val);
        Prev(root->left);
        Prev(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        Prev(root);
        int min = INT_MAX;
        for(auto i : vec){
            for(auto j : vec){
                if(i != j && abs(i - j) < min) min = abs(i - j);
            }
        }
        return min;
    }
};
// @lc code=end

