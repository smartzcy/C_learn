#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0 , j = nums.size();
        while(i <= j){
            int m = (i + j) / 2;
            if(nums[m] == target) return m;
            else if(nums[m] < target) i = m + 1;
            else if(nums[m] > target) j = m - 1;
        }
        return -1;
    }
};