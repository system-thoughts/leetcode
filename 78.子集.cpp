/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) {
            return {{}};
        }
        int n = nums.back();
        nums.pop_back();
        vector<vector<int>> sub_res = subsets(nums);
        auto res = sub_res;
        for (auto vec : sub_res) {
            vec.push_back(n);
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end

