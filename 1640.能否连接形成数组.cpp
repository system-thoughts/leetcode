/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> dict;
        int i;
        for (int i = 0; i < pieces.size(); i++) {
            dict[pieces[i][0]] = i;
        }
        i = 0;
        while (i < arr.size()) {
            int elem = arr[i];
            if (dict.find(elem) == dict.end()) {
                return false;
            }
            for (int j = 0; j < pieces[dict[elem]].size(); j++) {
                if (pieces[dict[elem]][j] != arr[i++])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

