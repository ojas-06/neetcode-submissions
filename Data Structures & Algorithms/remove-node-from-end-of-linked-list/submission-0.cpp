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
    pair<ListNode*, int> recurse(ListNode* head, int n){
        if(!head->next) return {nullptr, 1};
        auto p = recurse(head->next, n);
        if(p.second == n){
            ListNode* tmp = head->next;
            head->next = p.first;
            delete tmp;
            return {head->next, p.second+1};
        }
        return {head->next, p.second+1};
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(101);
        dummy->next = head;
        return recurse(dummy,n).first;
    }
};
