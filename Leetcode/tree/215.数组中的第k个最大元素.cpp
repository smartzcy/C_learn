/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> que;
        for(auto i : nums) que.push(i);
        for(int i = 1 ; i < k;i++){
            que.pop();
        }
        return que.top();
    }
};
// @lc code=end

