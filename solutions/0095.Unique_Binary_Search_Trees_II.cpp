/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

vector<TreeNode*> generateTree(int l, int r) {
    if (l > r)
        return {nullptr};
    vector<TreeNode*> ans;
    for (int i = l; i < r + 1; i++) {
        vector<TreeNode*> left = generateTree(l, i - 1);
        vector<TreeNode*> right = generateTree(i + 1, r);
        for (auto& ll : left) {
            for (auto& rr : right) {
                TreeNode* root = new TreeNode(i, ll, rr);
                ans.push_back(root);
            }
        }
    }
    return ans;
}

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTree(1, n);
    }
};
// @lc code=end

