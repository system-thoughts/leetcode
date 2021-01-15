/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    void connect(vector<string>& res, string S) {
        if (res.empty()) {
            if (S[0] >= 'a' && S[0] <= 'z') {
                res.push_back(string(1, S[0] - 'a' + 'A'));
            } else if (S[0] >= 'A' && S[0] <= 'Z') {
                res.push_back(string(1, S[0] - 'A' + 'a'));
            }
            res.push_back(S);
        } else {
            vector<string> copy;
            if ((S[0] >= 'a' && S[0] <= 'z') || (S[0] >= 'A' && S[0] <= 'Z')) {
                auto it = copy.begin();
                copy.insert(it, res.begin(), res.end());
                for (auto& str : copy) {
                    if (S[0] >= 'a' && S[0] <= 'z')
                        str += string(1, 'A' - 'a' + S[0]);
                    else
                        str += string(1, 'a' - 'A' + S[0]);
                }
            }
            for (auto& str : res) {
                str += S;
            }
            if (!copy.empty()) {
                auto it = res.begin();
                res.insert(it, copy.begin(), copy.end());
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if (S.size() == 0) {
            return res;
        }
        while (!S.empty()) {
            connect(res, S.substr(0,1));
            auto it = S.begin();
            S.erase(it);
        }
        return res;
    }
};
// @lc code=end

