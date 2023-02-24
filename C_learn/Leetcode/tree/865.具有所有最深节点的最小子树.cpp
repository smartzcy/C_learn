/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
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
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    int getMax(TreeNode *root){
        if(root == NULL) return 0;
        return max(getMax(root->left) , getMax(root->right)) + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL) return NULL;
        int left = getMax(root->left);
        int right = getMax(root->right);
        if(left == right) return root;
        if(left > right) return subtreeWithAllDeepest(root->left);
        return subtreeWithAllDeepest(root->right);
    }
};
// @lc code=end

