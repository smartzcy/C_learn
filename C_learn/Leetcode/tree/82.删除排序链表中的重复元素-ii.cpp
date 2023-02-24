/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* temp = new ListNode();
        ListNode* head1 = temp;
        int num = head->val;
        head = head->next;
        int flag = 0;
        while(head != NULL){
            if(num != head->val){
                if(flag == 0){
                    ListNode* temp1 = new ListNode(num);
                    head1->next = temp1;
                    head1 = head1->next;
                }
                num = head->val;
                flag = 0;
            }else{
                flag = 1;
            }
            head = head->next;
        }
        if(flag == 0) {
            ListNode* temp1 = new ListNode(num);
            head1->next = temp1;
            head1 = head1->next;
        }
        return temp->next;
    }
};
// @lc code=end

