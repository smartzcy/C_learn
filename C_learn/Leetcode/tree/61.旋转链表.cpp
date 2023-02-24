/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        if(head == NULL) return head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        k %= count;
        for(int i = 0 ; i < k;i++){
            temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            ListNode* temp1 = temp->next;
            temp1->next = head;
            temp->next = NULL;
            head = temp1;
        }
        return head;
    }
};
// @lc code=end

