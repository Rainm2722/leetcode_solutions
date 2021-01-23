/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        string ss = "";
        for (int i = 0; i < s.length(); i++){
            for (int j = 0; j < ss.length(); j++)
                if (s[i] == ss[j])  ss.erase(0,j+1);
            ss += s[i];
            ans = (ans > ss.length())? ans : ss.length(); 
        }
        return ans;
    }
};
// @lc code=end

