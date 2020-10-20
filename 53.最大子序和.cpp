/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> maxSumIndexTail(nums.size());

        maxSumIndexTail[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxSumIndexTail[i] = max(maxSumIndexTail[i-1] + nums[i], nums[i]);
        }

        int maxSubLen = maxSumIndexTail[0];
        for (int i = 1; i < maxSumIndexTail.size(); i++) {
            if (maxSubLen < maxSumIndexTail[i])
                maxSubLen = maxSumIndexTail[i];
        }
        return maxSubLen;
    }
};
// @lc code=end

