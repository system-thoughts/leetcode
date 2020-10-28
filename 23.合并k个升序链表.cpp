/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode* tail = res;
        for (auto list : lists) {
            mergeTwoLists(res->next, list, tail);
        }
        return res->next;       
    }
    void mergeTwoLists(ListNode* listA, ListNode* listB, ListNode *tail) {
        while (listA && listB)
        {
            if (listA->val < listB->val) {
                tail->next = new ListNode(listA->val);
                listA = listA->next;
            } else {
                tail->next = new ListNode(listB->val);
                listB = listB->next;
            }
            tail = tail->next;
        }
        ListNode *remain = listA ? listA : listB;
        while (remain)
        {
            tail->next = new ListNode(remain->val);
            remain = remain->next;
            tail = tail->next;
        }
    }
};
// @lc code=end

