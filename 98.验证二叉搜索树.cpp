/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        auto left = root->left;
        auto right = root->right;
        if ((left == nullptr || left->val < root->val) && (right == nullptr || right->val > root->val)) {
            return (left ? isValidBST(left) : true) && (right ? isValidBST(right) : true);
        }
        return false;
    }
};
// @lc code=end

