/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 * 通过先序遍历找到根节点
 * 通过中序遍历，确定该根节点对应的左子树和右子树的范围
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
    TreeNode* buildTreeHelper(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd) {
        int i;
        if (pStart == pEnd) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pStart]);
        // 在中序遍历数组中寻找到root节点从而确定左/右子树的范围
        for (i = iStart; i < iEnd; i++) {
            if (inorder[i] == preorder[pStart])
                break;
        }
        int leftRange = i - iStart;
        root->left = buildTreeHelper(preorder, pStart + 1, pStart + 1 + leftRange, inorder, iStart, i);
        root->right = buildTreeHelper(preorder, pStart + 1 + leftRange, pEnd, inorder, i + 1, iEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end

