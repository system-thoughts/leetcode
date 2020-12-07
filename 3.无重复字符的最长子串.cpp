/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        unordered_set<char> hash;
        for (int right = 0; right < s.size(); right++) {
            // 滑动窗口向右移动，若没有碰到重复元素，则一直移动
            // 反之，shrink sliding window
            if (hash.count(s[right])) {
                while (s[left] != s[right]) {
                    hash.erase(s[left++]);
                }
                hash.erase(s[left++]);
            }
            hash.emplace(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
// @lc code=end

