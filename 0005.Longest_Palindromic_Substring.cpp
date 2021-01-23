/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)  return s;
        int l, r, maxlen = 0, start = 0;
        for (int i = 0; i < s.size(); i ++){
            l = i - 1;
            r = i + 1;
            while (s[i] == s[r])  ++r;
            while (l >= 0 && s[l] == s[r]){
                --l;
                ++r;
            }
            if (r - l - 1 > maxlen){
                maxlen = r - l - 1;
                start = l + 1;
            }
        }
        return s.substr(start, maxlen);
    }
};
// @lc code=end

