/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        ans += m[s.substr(0, 1)];
        for (int i = 1; i < s.length(); ++i) {
            string ch1 = s.substr(i, 1);
            string ch2 = s.substr(i - 1, 2);
            if (m.count(ch2))
                ans += m[ch2];
            else
                ans += m[ch1];
        }
        return ans;
    }
};
// @lc code=end

