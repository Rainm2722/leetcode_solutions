/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i = 0, j = height.size() - 1;
        while (i != j){
            int tmp = min(height[i], height[j]) * (j - i);
            max = tmp > max ? tmp : max;
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return max;
    }
};
// @lc code=end

