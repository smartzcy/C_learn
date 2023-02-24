/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x) , next(nullptr){}
    ListNode(int x , ListNode *next) : val(x),next(next){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode();
        ListNode* temp1 = temp;
        while(list1 || list2){
            if(!list1 || ((list2)&&(list1->val > list2->val))){
                temp1->next = list2;
                list2 = list2->next;
            }else if(!list2 || ((list1) && list1->val <= list2->val)){
                temp1->next = list1;
                list1 = list1->next;
            }
            temp1 = temp1->next;
        }
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* temp = new ListNode();
        for(auto i : lists){
            temp = mergeTwoLists(temp,i);
        }
        return temp->next;
    }
};
// @lc code=end

