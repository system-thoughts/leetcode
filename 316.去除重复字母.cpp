/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 * 最小字符序的字符串应该满足字符串中的字符尽量按照升序排列
 * 输出字符串为空 -- 字符直接进入字符串
 * 字符已经在字符串中存在 -- 跳过该字符
 * 当前字符比字符串中末尾的字符要小 -- 如果遍历字符后面仍然存在末尾字符，则末尾字符需要从字符串中弹出，遍历字符进入字符串
 * -- 若不存在末尾字符，遍历字符同样进入队列
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (!res.empty() && res.find(s[i]) != std::string::npos) {
                continue;
            }
            while (!res.empty() && *(res.rbegin()) > s[i] && s.find(*(res.rbegin()), i) != std::string::npos) {
                res.pop_back();
            }
            res.push_back(s[i]);
        }
        return res;
    }
};
// @lc code=end

