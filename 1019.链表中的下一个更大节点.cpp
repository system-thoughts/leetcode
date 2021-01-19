/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<ListNode *> st;
        vector<int> res;
        unordered_map<ListNode *, int> map;

        auto p = head;
        while (p != nullptr) {
            if (st.empty() || p->val <= st.top()->val) {
                st.push(p);
            } else {
                while (!st.empty() && p->val > st.top()->val) {
                    map[st.top()] = p->val;
                    st.pop();
                }
                st.push(p);
            }
            p = p->next;
        }
        while (!st.empty()) {
            map[st.top()] = 0;
            st.pop();
        }
        p = head;
        while (p != nullptr) {
            res.push_back(map[p]);
            p = p->next;
        }
        return res;
    }
};
// @lc code=end

