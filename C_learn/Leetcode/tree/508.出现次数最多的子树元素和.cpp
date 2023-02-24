/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    int Prev(TreeNode* root , int x , int y){
        if(root == NULL) return 0;
        x += Prev(root->left , x , y);
        y += Prev(root->right , y , y);
        map1[x + y + root->val]++;
        return x + y + root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        Prev(root, 0 , 0);
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

