/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        while(head != NULL){
            if(num != head->val){
                ListNode* temp1 = new ListNode(num);
                head1->next = temp1;
                head1 = head1->next;
                num = head->val;
            }
            head = head->next;
        }
        head1->next = new ListNode(num);
        return temp->next;
    }
};
// @lc code=end

