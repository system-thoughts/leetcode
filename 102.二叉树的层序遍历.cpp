/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 * 在层序遍历之前，需要记录队列中节点的数量，表示当前层次的节点数目
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto size = q.size();
            vector<int> vec;
            for (auto i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end

