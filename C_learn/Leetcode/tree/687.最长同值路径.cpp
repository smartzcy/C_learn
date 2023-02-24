/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int Find(TreeNode* root , int x){
        if(root == NULL) return 0;
        if(x == root->val){
            return 1 + max(Find(root->left , x) , Find(root->right , x));
        }else{
            return 0;
        }
    }
    int max1 = 0;
    void Prev(TreeNode* root){
        if(root == NULL) return ;
        max1 = max(max1 , Find(root->left , root->val) + Find(root->right , root->val));
        Prev(root->left);
        Prev(root->right);
    }
    int longestUnivaluePath(TreeNode* root) {
        Prev(root);
        return max1;
    }
};
// @lc code=end

