/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 起点即终点，不用跳
        if (nums.size() == 1)
            return true;
        return jump(nums, 0, nums[0]);
    }
    bool jump(vector<int>& nums, int pos, int len) {
        // 如果当前位置，能够跳的最大距离能够到达数组末尾，则肯定能够跳到数组末尾
        if (pos + len >= nums.size() - 1) {
            return true;
        }
        for (int i = len; i > 0; i--) {
            // 尝试使用各种跳跃长度进行跳跃，当然跳跃长度不能为0（原地不动）
            if (jump(nums, pos + i, nums[pos + i]))
                return true;
        }
        return false;
    }
};
// @lc code=end

