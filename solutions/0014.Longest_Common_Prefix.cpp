/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.size() == 0 || strs[0] == "")
            return ans; 
        for (int i = 0; i < strs[0].length(); ++i) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (ch != strs[j][i])
                    return ans;
            }
            ans += ch;
        }
        return ans;
    }
};
// @lc code=end

