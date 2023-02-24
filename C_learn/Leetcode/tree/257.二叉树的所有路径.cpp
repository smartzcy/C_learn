/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include<string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    void Prev(TreeNode* root , string str , vector<string>& vec){
        if(root != NULL){
            str += to_string(root->val);
            if(root->left == NULL && root->right == NULL){
                vec.push_back(str);
            }else{
                str += "->";
                Prev(root->left,str,vec);
                Prev(root->right,str,vec);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        Prev(root,"",vec);
        return vec;
    }
};
// @lc code=end

