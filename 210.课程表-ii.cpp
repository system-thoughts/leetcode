/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    // 如果图中有环，返回true
    int dfs(int start, const vector<vector<int>>& schedule, vector<int>& visited, unordered_set<int> &order) {
        // 该节点在其他路径上已经被访问过，该路径上不存在环
        if (visited[start] == -1) {
            return start;
        }
        // 在当前路径上访问到路径之前的节点，形成环
        if (visited[start] == 1) {
            return -1;
        }
        visited[start] = 1;
        int depend = -2;
        for (const auto & n : schedule[start]) {
            // 邻接节点触发的路径上形成环
            depend = dfs(n, schedule, visited, order);
            if (depend == -1) {
                return -1;
            }
        }
        // 尚且不在序列里面
        if (order.count(start) == 0) {
            auto it = depend == 2 ? order.end() : order.find(depend);
            order.insert(it, start);
        }
        visited[start] = -1;
        return start;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> schedule(numCourses);
        vector<int> visited(numCourses, 0);
        unordered_set<int> order;

        for (const auto & relation : prerequisites) {
            schedule[relation[0]].push_back(relation[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            // 不依赖任何课程，顺序随意
            if (schedule[i].size() == 0) {
                order.insert(order.end(), i);
                continue;
            }
            if (dfs(i, schedule, visited, order) == -1) {
                order.clear();
                break;
            }
        }
        auto tmp = vector(order.begin(), order.end());
        return vector(tmp.rbegin(), tmp.rend());
    }
};
// @lc code=end

