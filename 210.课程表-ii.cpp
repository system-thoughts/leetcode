/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 构造图
        vector<vector<int>> graph(numCourses);
        // 入度表
        vector<int> inDegree(numCourses);
        // 入度为0的节点
        queue<int> q;
        vector<int> res;
        for (const auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            res.push_back(node);
            for (const auto& n : graph[node]) {
                if (--inDegree[n] == 0)
                    q.push(n);
            }
        }
        if (res.size() != numCourses)
            res.clear();
        return res;
    }
};
// @lc code=end

