/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        int num1, num2, tmp;
        ListNode *ptr = ans;
        ptr->val = (l1->val + l2->val) % 10;
        tmp = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2){
            if (!l1) num1 = 0; else num1 = l1->val;
            if (!l2) num2 = 0; else num2 = l2->val;
            ptr->next = new ListNode((num1 + num2 + tmp) % 10, nullptr);
            tmp = (num1 + num2 + tmp) / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            ptr = ptr->next;
        }
        if (tmp > 0){
            ptr->next = new ListNode(tmp, nullptr);
        }
        return ans;
    }
};
// @lc code=end

