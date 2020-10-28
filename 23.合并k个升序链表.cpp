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

class compare {
public:
    bool operator() (const ListNode& a, const ListNode& b) const {return a.val > b.val;}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode *tail = res;
        priority_queue<ListNode, vector<ListNode>, compare> pq;
        for (auto list : lists)
        {
            while (list)
            {
                pq.push(*list);
                list = list->next;
            }
        }
        while (!pq.empty())
        {
            tail->next = new ListNode(pq.top().val);
            pq.pop();
            tail = tail->next;
        }
        return res->next;
    }
};
// @lc code=end

