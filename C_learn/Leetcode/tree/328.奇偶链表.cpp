/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *head1 = new ListNode() , *head2 = new ListNode();
        ListNode *temp1 = head1 , *temp2 = head2;
        int flag = 1;
        while(head != NULL){
            if(flag % 2 == 1){
                temp1->next = new ListNode(head->val);
                temp1 = temp1->next;
            }else{
                temp2->next = new ListNode(head->val);
                temp2 = temp2->next;
            }
            flag++;
            head = head->next;
        }
        temp1->next = head2->next;
        return temp1->next;
    }
};
// @lc code=end

