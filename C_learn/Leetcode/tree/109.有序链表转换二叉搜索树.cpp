/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x) , next(nullptr) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* Insert(vector<int>& nums , int left , int right){
        if(left > right) return NULL;
        int m = (left + right) / 2;
        TreeNode* temp = new TreeNode(nums[m]);
        temp->left = Insert(nums,left,m - 1);
        temp->right = Insert(nums,m + 1, right);
        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        return Insert(nums,0,nums.size() - 1);
    }
};
// @lc code=end

