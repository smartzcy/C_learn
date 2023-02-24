/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        string str = "aeiouAEIOU";
        int a1 = 0 , a2 = 0;
        for(int i = 0 ; i < s.length() / 2;i++){
            if(str.find(s[i]) != str.npos){
                a1++;
            }
        }
        for(int i = s.length() / 2 ; i < s.length();i++){
            if(str.find(s[i]) != str.npos){
                a2++;
            }
        }
        if(a1 == a2) return true;
        else return false;
    }
};
// @lc code=end

