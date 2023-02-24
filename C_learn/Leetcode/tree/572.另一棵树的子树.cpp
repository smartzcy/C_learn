/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
#include<string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    void Prev(TreeNode* root , string &a){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) a += " ";
        Prev(root->left,a);
        a += to_string(root->val);
        Prev(root->right,a);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 , s2;
        Prev(root , s1);
        Prev(subRoot , s2);
        if(s1.find(s2) != s1.npos) return true;
        else return false;
    }
};
// @lc code=end

