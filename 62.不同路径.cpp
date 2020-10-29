/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 * 不使用递归，根据动态方程正向推导得到最终结果
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int i, j;
        vector<vector<int>> path(m, vector<int>(n, 0));
        for (i = 0; i < n; i++)
        {
            path[0][i] = 1;
        }
        for (i = 1; i < m; i++)
        {
            path[i][0] = 1;
        }
        for (i = 1; i < m; i++)
        {
            for (j = 1; j < n; j++)
            {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
        return path[m - 1][n - 1];
    }
};
// @lc code=end
