/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    void Prev(TreeNode* root , vector<int>& vec){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) vec.push_back(root->val);
        Prev(root->left , vec);
        Prev(root->right , vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1 , vec2;
        Prev(root1,vec1);
        Prev(root2,vec2);
        if(vec1.size() == vec2.size()){
            for(auto i = vec1.begin() ,  j = vec2.begin() ; i != vec1.end() , j != vec2.end();i++,j++){
                if(*i != *j) return false;
            }
            return true;
        }
        return false;
    }
};
// @lc code=end

