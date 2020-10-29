/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 * 超时是应该的，想想m和n较大时，这个栈得有多深
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};
// @lc code=end

