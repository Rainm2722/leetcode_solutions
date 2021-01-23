/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy = nums;
        vector<int> ans;
        sort(copy.begin(), copy.end());
        vector<int>::iterator it1, it2;
        it1 = copy.begin();
        it2 = copy.end() - 1;
        while(*it1 + *it2 != target){
            if (*it1 + *it2 < target) ++it1;
            else --it2;
        }
        for (auto it = nums.begin(); it < nums.end(); it++)
            if (*it == *it1)
                ans.push_back(it - nums.begin());
            else if (*it == *it2)
                ans.push_back(it - nums.begin());
        return ans;
    }
};
// @lc code=end

