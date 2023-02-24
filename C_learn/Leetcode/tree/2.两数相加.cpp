/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x) , next(nullptr){}
    ListNode(int x , ListNode *next) : val(x),next(next){}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* head = NULL;
        // int num = 0;
        // while(l1 != NULL && l2 != NULL){
        //     ListNode* temp1 = new ListNode();
        //     temp1->val = (l1->val + l2->val + num) % 10;
        //     if((l1->val + l2->val + num) / 10 != 0) num = 1;
        //     else num = 0;
        //     temp1->next = NULL;
        //     if(head == NULL) head = temp1;
        //     else{
        //         ListNode* temp = head;
        //         while(temp->next != NULL) temp = temp->next;
        //         temp->next = temp1;
        //     }
        //     l1 = l1->next;
        //     l2 = l2->next;
        // }
        // while(l1 != NULL){
        //     ListNode* temp1 = new ListNode();
        //     temp1->val = (l1->val + num) % 10;
        //     if((l1->val + num) / 10 != 0) num = 1;
        //     else num = 0;
        //     temp1->next = NULL;
        //     ListNode* temp = head;
        //     while(temp->next != NULL) temp = temp->next;
        //     temp->next = temp1;
        //     l1 = l1->next;
        // }
        // while(l2 != NULL){
        //     ListNode* temp1 = new ListNode();
        //     temp1->val = (l2->val + num) % 10;
        //     if((l2->val + num) / 10 != 0) num = 1;
        //     else num = 0;
        //     temp1->next = NULL;
        //     ListNode* temp = head;
        //     while(temp->next != NULL) temp = temp->next;
        //     temp->next = temp1;
        //     l2 = l2->next;
        // }
        // if(num == 1){
        //     ListNode* temp = head;
        //     while(temp->next != NULL) temp = temp->next;
        //     ListNode* temp1 = new ListNode();
        //     temp1->val = 1;
        //     temp1->next = NULL;
        //     temp->next = temp1;
        // }
        // return head;
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        int num = 0;
        while(l1 || l2 || num){
            if(l1) num += l1->val;
            if(l2) num += l2->val;
            ListNode* temp1 = new ListNode(num % 10);
            num /= 10;
            head->next = temp1;
            head = head->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head->next;
    }
};
// @lc code=end

