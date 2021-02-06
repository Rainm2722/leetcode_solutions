
/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += cardPoints[i];
        }

        int sum = 0;
        for (int i = 0; i < n - k; ++i) {
            sum += cardPoints[i];
        }

        int curr = sum;
        for (int i = n - k; i < n; ++i) {
            curr = curr - cardPoints[i - (n - k)] + cardPoints[i];
            sum = min(curr, sum); 
        }

        return total - sum;
    }
};
// @lc code=end

