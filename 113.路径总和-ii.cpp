/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &pathTotal) {
        if (root == nullptr)
            return;
        // 把当前节点加入到路径中
        path.push_back(root->val);
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum) {
                pathTotal.push_back(path);
            }
            path.pop_back();
            return;
        }
        dfs(root->left, sum - root->val, path, pathTotal);
        dfs(root->right, sum - root->val, path, pathTotal);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> pathTotal;
        vector<int> path;
        dfs(root, sum, path, pathTotal);
        return pathTotal;
    }
};
// @lc code=end

