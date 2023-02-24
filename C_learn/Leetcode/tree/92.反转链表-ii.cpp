/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* Reverse(ListNode* head){
        ListNode *temp = head , *prev = NULL;
        while(temp != NULL){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp2 = new ListNode(),*temp3 = new ListNode();
        ListNode *head1 = temp2 , *head2 = temp3;
        for(int i = 1 ;i < left;i++){
            head1->next = new ListNode(head->val);
            head1 = head1->next;
            head = head->next;
        }
        for(int i = left ; i <= right;i++){
            head2->next = new ListNode(head->val);
            head2 = head2->next;
            head = head->next;
        }
        temp3 = Reverse(temp3->next);
        head1->next = temp3;
        while(temp3->next != NULL) temp3 = temp3->next;
        temp3->next = head;
        return temp2->next;
    }
};
// @lc code=end

