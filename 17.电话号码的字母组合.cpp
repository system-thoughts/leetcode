/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 * 深度优先搜索
 * 每一层都输出一个转换字符到结果字符串，直到指定长度的字符串被转换完，转换结果字符串才输出到容器中
 * 使用深度优先搜索能够保证一次完整的深度调用栈能够将字符串全部转换
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        unordered_map<char, string> table{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        if (digits.empty())
        {
            return res;
        }
        transfer("", digits, table, 0, res);
        return res;
    }

    void transfer(string s, string &digits, unordered_map<char, string> &table, int order, vector<string> &res)
    {
        if (s.size() == digits.size())
        {
            res.push_back(s);
            return;
        }
        string characters = table[digits[order]];
        for (char c : characters)
        {
            s += c;
            transfer(s, digits, table, order + 1, res);
            s.pop_back();
        }
        return;
    }
};
// @lc code=end
