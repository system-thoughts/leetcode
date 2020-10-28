/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string maxComPrefix = strs[0];
        int i, j;
        for (i = 1; i < strs.size(); i++) {
            auto len = min(maxComPrefix.size(), strs[i].size());
            for (j = 0; j < len; j++) {
                if (strs[i][j] != maxComPrefix[j])
                    break;
            }
            if (j < maxComPrefix.size())
                maxComPrefix.erase(j, maxComPrefix.size() - j);
        }
        return maxComPrefix;
    }
};
// @lc code=end

