/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
static int direction[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<int>> visited;
        visited.resize(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (visit(i, j, grid, visited))
                    count++;
            }
        }
        return count;
    }

    bool visit(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        // 超出边界
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return false;
        }
        if (grid[row][col] == '0' || visited[row][col]) {
            return false;
        }
        visited[row][col] = 1;
        // 如果起点是陆地，且未被访问过，则从起点出发，走遍所有连接的陆地
        for (int i = 0; i < 4; i++) {
            row += direction[i][0];
            col += direction[i][1];
            visit(row, col, grid, visited);
            // 回退到原地
            row -= direction[i][0];
            col -= direction[i][1];
        }
        return true;
    }
};
// @lc code=end

