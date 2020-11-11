/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 * 选取最中间的点做根节点；左右两边分别是左子树和右子树范围；这样左右子树会尽量平衡
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* treeBuild(vector<int>& vec, int start, int end) {
        if (start >= end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(vec[start + (end - start) / 2]);
        root->left = treeBuild(vec, start, start + (end - start) / 2);
        root->right = treeBuild(vec, start + (end - start) / 2 + 1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        ListNode *p = head;
        while (p != nullptr) {
            vec.push_back(p->val);
            p = p->next;
        }
        return treeBuild(vec, 0, vec.size());
    }
};
// @lc code=end

