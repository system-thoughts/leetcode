/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 * 有向图不能形成环
 * 先构建有向图
 * 遍历有向图，若访问的邻居节点已经被访问说明有向图形成环
 */

// @lc code=start
class Solution {
public:
    // 形成环，返回true
    bool dfs(int start, vector<int>& visited, const vector<vector<int>>& schedule) {
        // 在另外一条路径上访问过，但未形成环
        if (visited[start] == -1)
            return false;
        // 本路径上之前访问过
        if (visited[start] == 1)
            return true;
        visited[start] = 1;
        for (const auto & n : schedule[start]) {
            if (dfs(n, visited, schedule))
                return true;
        }
        visited[start] = -1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> schedule(numCourses);
        vector<int> visited(numCourses, 0);

        for (const auto & relation : prerequisites) {
            schedule[relation[0]].push_back(relation[1]);
        }
        for (int i = 0; i < schedule.size(); i++) {
            // 如果课程没有依赖，略过
            if (schedule[i].size() == 0)
                continue;
            if (dfs(i, visited, schedule))
                return false;
        }
        return true;
    }
};
// @lc code=end

