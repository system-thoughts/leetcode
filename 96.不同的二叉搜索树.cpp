/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 * 以数值i为顶点构成的排序二叉树个数为f(i)
 * 则整数n的所有二叉搜索树的个数是：G(n)
 * G(n) = f(1) + f(2) + ... + f(n-1) + f(n)
 * 以数值i为顶点，左子树有i-1个顶点，右子树有n-i个顶点
 * 所以f(i) = G(i-1)*G(n-i)
 * 以n = 5, i = 3为例
 * f(3) = G(2) * G(2)
 * 第一个G(2) 表示顶点1,2构成的二叉搜索树的总数
 * 第二个G(2) 表示顶点4,5构成的二叉搜索树的总数
 * 因此G(n) = G(0)*G(n-1) + G(1)*G(n-2) + ... + G(n-1)*G(0)
 * 如G(2) = G(0)*G(1) + G(1)*G(0)
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1, 0);
        res[0] = 1;
        res[1] = 1;
        // 外部循环，求G(i)
        for (int i = 2; i < n+1; i++) {
            // 内部循环，求f(j)
            for (int j = 1; j <= i; j++) {
                res[i] += res[j - 1] * res[i - j];
            }
        }
        return res[n];
    }
};
// @lc code=end

