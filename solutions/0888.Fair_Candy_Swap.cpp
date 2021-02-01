/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int sumA = 0, sumB = 0, diff = 0;
        for (int i = 0; i < A.size(); ++i) {
            sumA += A[i];
        }
        for (int j = 0; j < B.size(); ++j) {
            sumB += B[j];
        }

        int a = 0, b = 0;
        diff = sumA - sumB;
        while ((A[a] - B[b]) != (diff / 2)) {
            if ((A[a] - B[b]) < (diff / 2))
                ++a;
            else
                ++b;
        }
        vector<int> ans = {A[a], B[b]};
           return ans;
    }
};
// @lc code=end

