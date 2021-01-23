#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        num = numRows * 2 - 2
        ss = ['' for _ in range(numRows)]
        for i in range(len(s)):
            tmp = i % num
            if tmp < numRows:
                ss[tmp] += s[i]
            else:
                ss[num - tmp] += s[i]
        ans = ""
        for i in range(numRows):
            ans += ss[i]
        return ans
# @lc code=end

