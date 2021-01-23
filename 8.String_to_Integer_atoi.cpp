/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int start = 0, flag = 1;
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            if (c >= 'A' && c <= 'Z' || c >= 'z' && c <= 'z' || c == '.')  
                return 0;
            else if (c != ' '){
                start = i;
                break;
            }
        }
        long ans = 0;
        if (s[start] == '+'){
            ++start;
        }else if (s[start] == '-'){
            ++start;
            flag = -1;
        }
        for (int i = start; i < s.size(); i++){
            char c = s[i];
            if (c < '0' || c > '9') break;
            ans *= 10;
            ans += flag * (c - '0');
            if (ans > INT_MAX) return INT_MAX;
            if (ans < INT_MIN) return INT_MIN;
        }
        return ans;
    }
};
// @lc code=end

