/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 *
 * [1702] 修改后的最大二进制字符串
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string maximumBinaryString(string binary) {
        string str = "aeiouAEIOU";
        for(int i = 0 ; i < binary.length() / 2;i++){
            if(str.find(binary[i]) != str.npos){
                
            }
        }
    }
};
// @lc code=end

