/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 * Dijkstra算法求所有路径中的最短路径
 * 若有节点不可达则返回-1
 * 由于优先队列中间的元素无法直接更新，所以优先队列中可能会存在多个同样的节点
 * 此时需要一个冗余的数据结构来记录当前节点在known集中，及已经求得了最短距离
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // 第一个参数表示K->S的距离，第二个参数表示目标节点S
        using path = pair<int, int>;
        vector<int> dis(N+1, numeric_limits<int>::max()); // 到每个节点的最短路径
        vector<int> known(N+1, 0);
        priority_queue<path, vector<path>, greater<path>> pq;

        // 构建图
        unordered_map<int, vector<path>> map;
        for (const auto& t: times) {
            map[t[0]].push_back({t[2], t[1]});
        }
        dis[K] = 0;
        pq.push({dis[K], K});

        while (!pq.empty()) {
            auto elem = pq.top();
            pq.pop();
            int node = elem.second;
            int distance = elem.first;
            // 若节点的最短路径已经求得，则忽略
            if (known[node])
                continue;
            // 遍历所有邻居
            for (const auto& p : map[node]) {
                if (distance + p.first < dis[p.second]) {
                    dis[p.second] = distance + p.first;
                    pq.push(path(dis[p.second], p.second));
                }   
            }
        }

        int ans = *max_element(dis.begin()+1, dis.end());
        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};
// @lc code=end

