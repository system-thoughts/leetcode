/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0, 0, 0};
        for (auto i : nums) {
            a[i]++;
        }
        int base = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < a[i]; j++)
                nums[base + j] = i;
            base += a[i];
        }
    }
};
// @lc code=end

