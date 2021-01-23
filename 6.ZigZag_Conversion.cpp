/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start

/* ----- method 1 ----- */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        vector<string> ss(min(numRows, int(s.size())));
        int num = numRows * 2 - 2;
        for (int i = 0; i < s.size(); i++){
            int tmp = i % num;
            if (tmp < numRows)
                ss[tmp] += s[i];
            else
                ss[num - tmp] += s[i];
        }
        string ans = "";
        for (int i = 0; i < numRows; i++)
            ans += ss[i];
        return ans;
    }
};

/* ----- method 2 ----- */
class Solution2 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        vector<string> ss(min(numRows, int(s.size())));
        int flag = 1, index = 0;
        for (int i = 0; i < s.size(); i++){
            ss[index] += s[i];
            index += flag;
            if (index == 0 || index == numRows - 1)
                flag *= -1;
        }
        string ans;
        for (int i = 0; i < ss.size(); i++)
            ans += ss[i];
        return ans;
    }
};
// @lc code=end

