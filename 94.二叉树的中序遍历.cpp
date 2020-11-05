/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *p = root;
        vector<TreeNode *> stk;
        vector<int> res;
        while (p || !stk.empty()) {
            while (p) {
                stk.push_back(p);
                p = p->left;
            }
            p = stk.back();
            res.push_back(p->val);
            stk.pop_back();
            p = p->right;
        }
        return res;
    }
};
// @lc code=end

