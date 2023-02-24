/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    // priority_queue<int> erase1(priority_queue<int> que , int k){
    //     priority_queue<int> que1;
    //     int flag = 0;
    //     while(!que.empty()){
    //         if(que.top() != k || flag == 1){
    //             que1.push(que.top());
    //         }else if(que.top() == k && flag == 0){
    //             flag = 1;
    //         }
    //         que.pop();
    //     }
    //     return que1;
    // }
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> vec;
    //     priority_queue<int> que;
    //     for(int i = 0 ; i < k;i++){
    //         que.push(nums[i]);
    //     }
    //     vec.push_back(que.top());
    //     int num = 0;
    //     for(int i = k ; i < nums.size() ; i++){
    //         que = erase1(que,nums[num++]);
    //         que.push(nums[i]);
    //         vec.push_back(que.top());
    //     }
    //     return vec;
    // }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> q;
        for(int i = 0 ; i < k;i++){
            q.emplace(nums[i],i);
        }
        vector<int> vec = {q.top().first};
        for(int i = k ; i < n;i++){
            q.emplace(nums[i],i);
            while(q.top().second <= i - k){
                q.pop();
            }
            vec.push_back(q.top().first);
        }
        return vec;
    }
};
// @lc code=end

