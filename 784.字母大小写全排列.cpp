/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        
        dfs(res, S, 0, string());
        return res;
    }
    void dfs(vector<string>& res, const string& S, int depth, string newS) {
        if (depth >= S.size()) {
            res.push_back(newS);
            return;
        }
        if (isdigit(S[depth]))
            dfs(res, S, depth + 1, newS + string(1, S[depth]));
        else {
            dfs(res, S, depth + 1, newS + string(1, tolower(S[depth])));
            dfs(res, S, depth + 1, newS + string(1, toupper(S[depth])));
        }
    }
};
// @lc code=end

