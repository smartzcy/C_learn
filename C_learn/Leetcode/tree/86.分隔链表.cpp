/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode();
        ListNode* head2 = new ListNode();
        ListNode *temp1 = head1,*temp2 = head2;
        while(head != NULL){
            if(head->val < x){
                temp1->next = new ListNode(head->val);
                temp1 = temp1->next;
            }else{
                temp2->next = new ListNode(head->val);
                temp2 = temp2->next;
            }
            head = head->next;
        }
        temp1->next = head2->next;
        return temp1->next;
    }
};
// @lc code=end

