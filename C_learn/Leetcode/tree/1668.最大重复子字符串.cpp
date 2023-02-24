/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        for(int i = 0 ;i <= sequence.length() - word.length();i++){
            if(sequence.substr(i,word.length()) == word){
                count++;
                i += word.length() - 1;
            }
        }
        return count;
    }
};
// @lc code=end

