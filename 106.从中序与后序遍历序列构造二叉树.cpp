/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 * 根据后续遍历，找到根节点，然后根据中序遍历，确定左子树和右子树的范围
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
    TreeNode* buildTreeHelper(unordered_map<int, int>& map, vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd) {
        if (pStart >= pEnd)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[pEnd - 1]);
        // 确定左子树，右子树的范围，确定根节点在中序遍历的位置
        int leftLen = map[postorder[pEnd - 1]] - iStart;
        root->left = buildTreeHelper(map, inorder, iStart, iStart + leftLen, postorder, pStart, pStart + leftLen);
        root->right = buildTreeHelper(map, inorder, iStart + leftLen + 1, iEnd, postorder, pStart + leftLen, pEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map.insert({inorder[i], i});
        }
        return buildTreeHelper(map, inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end

