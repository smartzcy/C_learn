/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    // ListNode* Delete(ListNode *head,int val){
    //     ListNode* temp1 = head;
    //     if(n == 1){
    //         head = temp1->next;
    //         delete temp1;
    //     }else{
    //         for(int i = 0 ; i < n - 2;i++){
    //             temp1 = temp1->next;
    //         }
    //         ListNode* temp2 = temp1->next;
    //         temp1->next = temp2->next;
    //         delete temp2;//释放内存
    //     }
    //     return head;
    // }
    ListNode* removeElements(ListNode* head, int val) {
    //     ListNode* temp = head;
    //     int count = 1;
    //     while(temp){
    //         if(val = temp->val) head = Delete(head,count);
    //         temp = temp->next;
    //         count++;
    //     }
    //     return head;
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* temp = dummyHead;
        while (temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return dummyHead->next;
    }
};
// @lc code=end

