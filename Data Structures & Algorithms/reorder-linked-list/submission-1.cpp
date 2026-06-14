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
    int size(ListNode* head){
        if(!head) return 0;
        return 1 + size(head->next);
    }
    void reorderList(ListNode* head) {
        int n = size(head);
        int count = 0;
        ListNode* ptr = head;
        while(count < (n-1)/2){
            ptr = ptr->next;
            count++;
        }
        stack<ListNode*> st;
        ListNode* p2 = ptr->next;
        ptr->next = nullptr;
        while(p2){
            st.push(p2);
            p2 = p2->next;
            st.top()->next = nullptr;
        }
        ListNode* p1 = head;
        while(!st.empty() && p1){
            if(p1->next) st.top()->next = p1->next;
            p1->next = st.top();
            st.pop();
            p1 = p1->next->next;
        }
    }
};
