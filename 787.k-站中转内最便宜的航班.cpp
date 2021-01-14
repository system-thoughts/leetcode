/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 * Dijkstra算法
 * Dijkstra在求最短路径的过程中要记录中间过程中到达dst的花费，因为最短路径可能会因为K的约束，而不成立
 * 由于优先队列中间的元素无法直接更新，所以优先队列中可能会存在多个同样的节点
 * 此时需要一个冗余的数据结构来记录当前节点在known集中，及已经求得了最短距离(因为优先级队列中存在元素已经计算出最短路径，但是仍然有中间过程继续保存)
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        int step = 0;
        // 第一个参数代表S->D的开销，第二个参数代表目标节点D
        using path = pair<int, int>;
        // 最短路径
        vector<int> dis(n, numeric_limits<int>::max());
        // 已经计算过最短路径的节点集合
        vector<int> known(n);
        // 优先级队列
        priority_queue<path, vector<path>, greater<path>> pq;

        // 构造图
        unordered_map<int, vector<path>> graph;
        for (const auto& f : flights) {
            graph[f[0]].push_back({f[2], f[1]});
        }
        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty() && step <= K) {
            auto element = pq.top();
            pq.pop();
            step++;
            int node = element.second;
            int distance = element.first;
            // 若节点的最短路径已经计算出来，忽略
            if (known[node])
                continue;
            known[node] = 1;
            if (node == dst)
                break;
            // 遍历所有邻居
            for (const auto& n : graph[node]) {
                int oldDistance = dis[n.second];
                int newDistance = dis[node] + distance;
                if (newDistance < oldDistance) {
                    dis[n.second] = newDistance;
                    pq.push({newDistance, n.second});
                }
            } 
        }
        return dis[dst] == 0 ? -1 : dis[dst];
    }
};
// @lc code=end

