/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
#include<map>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    map<int,int> map1;
    void Prev(TreeNode* root){
        if(root == NULL) return ;
        map1[root->val]++;
        Prev(root->left);
        Prev(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        Prev(root);
        vector<int> vec;
        int k = -1;
        for(auto i : map1){
            if(i.second > k){
                k = i.second;
                vec.clear();
                vec.push_back(i.first);
            }else if(i.second == k){
                vec.push_back(i.first);
            }
        }
        return vec;
    }
};
// @lc code=end

