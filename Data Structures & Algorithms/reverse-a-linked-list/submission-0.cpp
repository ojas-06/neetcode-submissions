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
    pair<ListNode*, ListNode*> f(ListNode* head){
        if(!head) return {nullptr,nullptr};
        if(!head->next) return {head,head};
        auto p = f(head->next);
        ListNode* curr = p.first, *lhead = p.second;
        curr->next = head;
        head->next = nullptr;
        return {head, lhead};
    }
    ListNode* reverseList(ListNode* head) {
        auto p = f(head);
        return p.second;

    }
};
