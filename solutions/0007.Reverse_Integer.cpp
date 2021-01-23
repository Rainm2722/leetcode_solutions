/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x / 10 || x % 10){
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        if (ans > 2147483647 || ans < -2147483648)
            return 0;
        return ans;
    }
};
// @lc code=end

