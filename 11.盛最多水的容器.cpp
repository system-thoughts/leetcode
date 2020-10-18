/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        long max_capacity = 0;
        for (auto left_bound = height.begin(); left_bound != height.end() - 1; left_bound++) {
            for (auto right_bound = left_bound + 1; right_bound != height.end(); right_bound++) {
                max_capacity = max(max_capacity, min(*left_bound, *right_bound) * (right_bound - left_bound));
            }
        }
        return max_capacity;
    }
};
// @lc code=end

