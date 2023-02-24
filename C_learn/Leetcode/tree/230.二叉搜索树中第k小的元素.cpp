/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
#include<set>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    set<int>set1;
    void Prev(TreeNode* root){
        if(root == NULL) return;
        set1.insert(root->val);
        Prev(root->left);
        Prev(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        Prev(root);
        int count = 0;
        for(auto i : set1){
            if(++count == k){
                return i;
            }
        }
    }
};
// @lc code=end

