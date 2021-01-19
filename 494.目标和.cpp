/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    void dfs(const vector<int>& nums, int S, int depth, int sum, int& count) {
        if (depth == nums.size()) {
            if (sum == S)
                count++;
            return;
        }
        dfs(nums, S, depth + 1, sum + nums[depth], count);
        dfs(nums, S, depth + 1, sum - nums[depth], count);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        dfs(nums, S, 0, 0, count);
        return count;
    }
};
// @lc code=end

