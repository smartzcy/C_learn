/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> vec1;
    vector<int> vec2;
    void Prev(TreeNode* root , int level){
        if(root == NULL) return ;
        if(level == vec2.size()) {
            vec2.push_back(0);
            vec1.push_back(0.0);
        }
        vec1[level]++;
        vec2[level] += root->val;
        Prev(root->left , level + 1);
        Prev(root->right , level + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        Prev(root , 0);
        for(int i = 0 ; i < vec1.size();i++){
            vec1[i] /= vec2[i];
        }
        return vec1;
    }
};
// @lc code=end

