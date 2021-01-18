/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        int i = 0;
        for (; i < intervals.size(); i++) {
            // 找到第一个比新区间右边界大的区间]
            if (newInterval[0] <= intervals[i][1])
                break;
            // 不会和当前区间相交
            res.push_back(intervals[i]);
        }
        // 得到第一个相交的区间
        int left = i;
        for (i = left; i < intervals.size(); i++) {
            // 找到第一个不在新区间左边界范围内的区间[
            if (newInterval[1] < intervals[i][0])
                break;
        }
        // 最后一个相交的区间
        int right = i;
        // 确定新的左边界
        newInterval[0] = left < intervals.size() ? min(newInterval[0], intervals[left][0]) : newInterval[0];
        // 确定新的右边界
        newInterval[1] = right >= 1 ? max(newInterval[1], intervals[right - 1][1]) : newInterval[1];
        res.push_back(newInterval);
        for (i = right; i < intervals.size(); i++)
            res.push_back(intervals[i]);
        return res;
    }
};
// @lc code=end

