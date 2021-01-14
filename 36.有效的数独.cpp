/
*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9));
        vector<vector<int>> col(9, vector<int>(9));
        vector<vector<int>> square(9, vector<int>(9));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int order = board[i][j] - '0' - 1;
                if (row[i][order] == 1 || col[j][order] == 1 ||
                    square[(i/3) * 3 + j / 3][order] == 1) {
                    return false;
                }
                row[i][order] = 1;
                col[j][order] = 1;
                square[(i / 3) * 3 + j / 3][order] = 1;
            }
        }
        return true;
    }
};
// @lc code=end

