/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 * 从边界上的'O'点开始搜索相连的点，将这些点都标记为visited
 * 所有边界上的点都遍历完之后，将区域中间的'O'点变为'x'
 */

// @lc code=start
static int direction[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int i, j;
        if (board.size() == 0) {
            return;
        }
        vector<vector<int>> visited;
        visited.resize(board.size(), vector<int>(board[0].size(), 0));
        for (i = 0; i < board[0].size(); i++) {
            visit(board, visited, 0, i);
            visit(board, visited, board.size()-1, i);
        }
        for (i = 1; i < board.size() - 1; i++) {
            visit(board, visited, i, 0);
            visit(board, visited, i, board[0].size() -1);
        }
        for (i = 1; i < board.size() - 1; i++) {
            for (j = 1; j < board[0].size() - 1; j++) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
    void visit(vector<vector<char>>& board, vector<vector<int>> &visited, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return;
        }
        if (board[x][y] == 'X' || visited[x][y]) {
            return;
        }
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            x += direction[i][0];
            y += direction[i][1];
            visit(board, visited, x, y);
            x -= direction[i][0];
            y -= direction[i][1];
        }
    }

};
// @lc code=end

