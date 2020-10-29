/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 * 以右上角的点为起点，同列向下的数值都比起点大，同行向左的数值都比起点小
 * 若target > 起点，起点向下移动
 * 若target < 起点，起点向左移动
 * 直到target == 起点，即找到起点 or 节点超出矩形的边界
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int posX, posY;
        if (matrix.size() == 0)
            return false;
        posX = 0;
        posY = matrix[0].size() - 1;
        while (posX < matrix.size() && posY >= 0) {
            if (matrix[posX][posY] < target) {
                posX += 1;         
            } else if (matrix[posX][posY] > target) {
                posY -= 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

