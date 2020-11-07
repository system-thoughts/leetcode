/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 * 输出的vector中的每个TreeNode *指的是树的根节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateSubTree(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for (int i = start; i <= end; i++) {
            auto leftTree = generateSubTree(start, i-1);
            auto rightTree = generateSubTree(i+1, end);
            for (auto& left : leftTree) {
                for (auto& right : rightTree) {
                    auto curNode = new TreeNode(i);
                    curNode->left = left;
                    curNode->right = right;
                    allTrees.emplace_back(curNode);
                }
            }
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateSubTree(1, n);
    }
};
// @lc code=end
