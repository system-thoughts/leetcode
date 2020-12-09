/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 * 求不连通图的个数
 */

// @lc code=start
class Solution {
public:
    void dfs(int start, const vector<vector<int>>& M, vector<int>& visited) {
        for (int i = 0; i < M[start].size(); i++) {
            if (M[start][i] && !visited[i]) {
                visited[i] = 1;
                dfs(i, M, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        vector<int> visited(M.size(), 0);
        for (int i = 0; i < M.size(); i++) {
            if (visited[i])
                continue;
            // 能做几次dfs就代表有几个不连通的图
            dfs(i, M, visited);
            count++;
        }
        return count;
    }
};
// @lc code=end

