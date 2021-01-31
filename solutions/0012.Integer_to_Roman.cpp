/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while (num / 1000) {
            ans += "M";
            num -= 1000;
        }

        int t = num / 100;
        num %= 100;
        if (t == 9)
            ans += "CM";
        else if (t == 4)
            ans += "CD";
        else {
            if (t >= 5) {
                ans += "D";
                t -= 5;
            }
            while (t) {
                ans += "C";
                --t;
            }
        } 

        t = num / 10;
        num %= 10;
        if (t == 9)
            ans += "XC";
        else if (t == 4)
            ans += "XL";
        else {
            if (t >= 5) {
                ans += "L";
                t -= 5;
            }
            while (t) {
                ans += "X";
                --t;
            }
        } 

        t = num;
        if (t == 9)
            ans += "IX";
        else if (t == 4)
            ans += "IV";
        else {
            if (t >= 5) {
                ans += "V";
                t -= 5;
            }
            while (t) {
                ans += "I";
                --t;
            }
        }
        return ans; 
    }
};

// greedy
class Solution1 {
public:
    string intToRoman(int num) {
        string ans;
        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> str = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for (int i = 0; i < val.size(); ++i) {
            while (num >= val[i]) {
                ans += str[i];
                num -= val[i];
            }
        }
        return ans;
    }
};
// @lc code=end

