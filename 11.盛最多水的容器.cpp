/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_capacity = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            max_capacity = max(max_capacity, min(height[i], height[j]) * (j - i));
            bool to_right = height[i] < height[j] ? true : false;
            to_right ? i++ : j--;
        }
        return max_capacity;
    }
};
// @lc code=end
