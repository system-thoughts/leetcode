/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    // It requires a and b are the same size
    bool less(vector<string> a, vector<string> b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i])
                return true;
            else if (a[i] > b[i])
                return false;
        }
        return false;
    }
    unordered_map<string, vector<string>> process(unordered_map<string, vector<string>> map, string k, int i) {
        map[k].erase(map[k].begin() + i);
        if (map[k].empty()) {
            auto it = map.find(k);
            map.erase(it);
        }
        return map;
    }
    void dfs(unordered_map<string, vector<string>> map, string start, vector<string>& res, vector<string> road) {
        if (map.empty()) {
            if (res.empty() || less(road, res))
                res = road;
        }
        for (int i = 0; i < map[start].size(); i++) {
            road.push_back(map[start][i]);
            dfs(process(map, start, i), map[start][i], res, road);
            // for the next road
            road.pop_back();
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> map;
        vector<string> res;

        if (tickets.empty())
            return res;
    
        for (auto t : tickets) {
            map[t[0]].push_back(t[1]);
        }
        dfs(map, "JFK", res, {"JFK"});
        return res;
    }
};
// @lc code=end

