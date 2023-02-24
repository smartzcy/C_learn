/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<vector<int>> vec;
    void Prev(TreeNode* root , int level){
        if(root == NULL) return ;
        if(level == vec.size()){
            vector<int> vec1;
            vec.push_back(vec1);
        }
        vec[level].push_back(root->val);
        Prev(root->left , level + 1);
        Prev(root->right , level + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> vec2;
        Prev(root , 0);
        for(auto i : vec){
            int max = INT_MIN;
            for(auto j : i){
                if(max < j) max = j;
            }
            vec2.push_back(max);
        }
        return vec2;
    }
};
// @lc code=end

