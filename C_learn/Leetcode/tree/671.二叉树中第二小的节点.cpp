/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
#include<set>
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
    set<int>set1;
    void Prev(TreeNode* root){
        if(root == NULL) return;
        int val;
        if(root->left != NULL && root->right != NULL){
            val = min(root->left->val , root->right->val);
        }else{
            val = root->val;
        }
        if(set1.find(val) == set1.end()) set1.insert(val);
        Prev(root->left);
        Prev(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        Prev(root);
        if(set1.size() == 1) return -1;
        return *(++set1.begin());
    }
};
// @lc code=end

