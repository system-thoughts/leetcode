/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    void dfs(TreeNode* from, unordered_map<int, vector<int>>& map, unordered_map<int, int>& visited) {
        TreeNode* to = nullptr;
        if (from->left != nullptr) {
            to = from->left;
            visited[from->val] = 0;
            visited[to->val] = 0;
            map[from->val].push_back(to->val);
            map[to->val].push_back(from->val);
            dfs(to, map, visited);
        }
        if (from->right != nullptr) {
            to = from->right;
            visited[from->val] = 0;
            visited[to->val] = 0;
            map[from->val].push_back(to->val);
            map[to->val].push_back(from->val);
            dfs(to, map, visited);
        }
    }
    void travel(unordered_map<int, vector<int>>& map, unordered_map<int, int>& visited, int start, int len, vector<int> &res)
    {
        if (len == 0) {
            res.push_back(start);
            return;
        }
        for (auto v : map[start]) {
            if (!visited[v]) {
                visited[v] = 1;
                travel(map, visited, v, len - 1, res);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // 将树转换为图
        unordered_map<int, vector<int>> map;
        unordered_map<int, int> visited;
        vector<int> res;
        dfs(root, map, visited);
        visited[target->val] = 1;
        travel(map, visited, target->val, K, res);
        return res;
    }
};
// @lc code=end

