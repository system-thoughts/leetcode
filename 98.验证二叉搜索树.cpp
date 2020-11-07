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
    bool isRangeValid(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr)
            return true;

        if (root->val <= lower || root->val >= upper)
            return false;
        return isRangeValid(root->left, lower, root->val) && isRangeValid(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isRangeValid(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

