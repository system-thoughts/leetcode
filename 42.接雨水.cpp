/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 * 使用单调递减栈保存墙的高度
 * 1. 只有比栈顶更高的墙要入栈的时候，雨水才能被接住
 *  1.1 此时栈顶元素出栈，该元素的高度记为base，新的栈顶元素便成为接水坑位的左侧
 *  1.2 坑位的长度 = l - r - 1
 *  1.3 坑位的高度 = min(height[l], height[r]) - base
 *  1.4 即便是高度相同的墙，应该直接入栈，因为他们都能够一起承接雨水
 *  1.5 出栈直到当前栈顶元素比入栈元素要大，保持了单调性
 * 2. 入栈该元素
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 左边界
        stack<int> bound;
        int capacity = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!bound.empty() && height[i] > height[bound.top()]) {
                int base = height[bound.top()];
                bound.pop();
                if (bound.empty())
                    break;
                int left = bound.top();
                int right = i;
                int h = min(height[left], height[right]) - base;
                capacity += (right - left - 1) * h;
            }
            bound.push(i);
        }
        return capacity;
    }
};
// @lc code=end

