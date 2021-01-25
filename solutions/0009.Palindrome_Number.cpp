/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x < 10)
            return true;
        long reverse = 0, xcopy = x;
        while (x / 10 || x % 10){
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }
        if (xcopy == reverse)   
            return true;
        else
            return false;
    }
};
// @lc code=end

