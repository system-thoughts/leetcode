/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 * 1. 如果作为起跳点的格子跳跃距离是3，随后的3个格子都是可以作为起跳点往后跳
 * 2. 可以对每个能作为起跳点的格子都尝试跳跃，更新能够跳跃到的最大距离
 * 3. 如果能够跳跃的最大距离能够达到数组终点，则成功；若最大距离都到不了下次跳跃的位置，则失败。
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDistance = 0;
        for (int pos = 0; pos < nums.size(); pos++) {
            // 最大距离达到不了下次跳跃的位置
            if (maxDistance < pos)
                return false;
            maxDistance = max(maxDistance, pos + nums[pos]);
            if (maxDistance >= nums.size() - 1)
                return true;
        }
        return true;
    }
};
// @lc code=end

