/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        string rs;
        int res;
        if (s[0] == '-') {
            s.push_back('-');
        }
        copy(s.crbegin(), s.crend(), back_inserter(rs));
        try {
            res = stoi(rs);
        } catch (const out_of_range& oor) {
            res = 0;
        }
        return res;
    }
};
// @lc code=end

