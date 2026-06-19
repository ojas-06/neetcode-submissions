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

class cmp{
public:
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val >= b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
       ListNode* head = nullptr, * ptr;
        for(auto &x:lists) pq.push(x);

        while(!pq.empty()){
            auto x = pq.top(); 
            pq.pop();
            if(!head) {
                head = x;
                ptr = x;
                if(x->next) pq.push(x->next);
                continue;
            }
            ptr->next = x;
            ptr = ptr->next;
            if(ptr->next) pq.push(ptr->next);
        } 
        return head;
    }
};
