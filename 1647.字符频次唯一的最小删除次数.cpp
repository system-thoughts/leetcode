/*
 * @lc app=leetcode.cn id=1647 lang=cpp
 *
 * [1647] 字符频次唯一的最小删除次数
 */

// @lc code=start
class Solution {
public:
    int minDeletions(string s) {
        int chars[26] = {0};
        int count = 0;
        set<int> times;
        for (char c : s)
            chars[c - 'a']++;
        for (int i : chars) {
            while (i != 0) {
                if (times.find(i) != times.end()) {
                    i--;
                    count++;
                } else {
                    times.insert(i);
                    break;
                }
            }
        }
        return count;
    }
};
// @lc code=end

