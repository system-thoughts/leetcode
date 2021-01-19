/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

// @lc code=start
class Solution {
public:
    vector<string> all(const string& S)
    {
        int start = 1;
        int end = start;
        vector<string> res;
        if (S.empty())
            return res;

        if (S.size() == 1) {
            res.push_back(S);
            return res;
        }
        if (S.front() != '0') {
            // 找到最后一个可以加小数点的位置
            if (S.back() == '0') {
                start = S.size();
                end = start;
            } else {
                end = S.size();
            }
        }
        // 添加小数点
        for (int i = start; i <= end; i++) {
            if (i == S.size())
                res.push_back(S);
            else {
                string integer = S.substr(0, i);
                string decimal = S.substr(i, S.size() - i);
                res.push_back(string(integer + "." + decimal));
            }
        }
        return res;
    }
    bool isValid(string S) {
        return (S.front() != '0' || S.back() != '0') || S == "0";
    }
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        if (S.empty())
            return res;

        S.erase(0, 1);
        S.pop_back();
        for (int i = 1; i <= S.size() - 1; i++) {
            string left = S.substr(0, i);
            string right = S.substr(i, S.size() - i);
            if (isValid(left) && isValid(right)) {
                vector<string> l = all(left);
                vector<string> r = all(right);
                for (int j = 0; j < l.size(); j++) {
                    for (int k = 0; k < r.size(); k++) {
                        res.push_back(string("(" + l[j] + ", " + r[k] + ")"));
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

