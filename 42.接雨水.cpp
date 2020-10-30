/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 * 使用栈保存墙的高度，如果当前墙的高度小于栈顶墙的高度，则将当前墙的高度入栈，因为这样后续可以有雨水存放的空间
 * 当前的墙高度若大于栈顶墙的高度，则将栈顶的墙出栈，计算积水容量
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 左边界
        stack<int> bound;
        int h;
        int capacity = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!bound.empty())
            {
                h = height[bound.top()];
                if (height[i] > h) {
                    bound.pop();
                    if (bound.empty()) {
                        break;
                    } else {
                        capacity += (min(height[i], height[bound.top()]) - h) * (i - bound.top() - 1);
                    }
                } else {
                    bound.push(i);
                    break;
                }
            }
            if (bound.empty()) {
                bound.push(i);
            }
        }
        return capacity;
    }
};
// @lc code=end

