/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start;
        for (start = 0; start < gas.size(); start++) {
            if (canTravel(gas, cost, start))
                break;
        }
        return start == gas.size() ? -1 : start;
    }
    bool canTravel(vector<int>& gas, vector<int>& cost, int start) {
        if (gas[start] < cost[start]) {
            return false;
        }
        int capacity = gas[start] - cost[start];
        int i = (start + 1) % gas.size();
        while(i != start && capacity >= 0) {
            capacity += (gas[i] - cost[i]);
            i = (i + 1) % gas.size();
        }
        return capacity < 0 ? false : true;
    }
};
// @lc code=end

