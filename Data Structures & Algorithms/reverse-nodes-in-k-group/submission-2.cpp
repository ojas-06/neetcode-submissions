class Solution {
public:
    ListNode* findKnode(ListNode* head, int k){
        if(!head) return nullptr; 
        if(k == 1) return head;
        if(!head->next) return nullptr;
        return findKnode(head->next, k-1);
    }
    ListNode* reverse(ListNode* a){
        if(!a || !a->next) return a;
        ListNode* r = reverse(a->next);
        r->next = a;
        a->next = nullptr;
        return a;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode* ptr = head;
        ListNode* res = head;
        ListNode* prevEnd = nullptr; 
        while(true){
            if(!ptr) break;
            ListNode* l = findKnode(ptr, k);
            if(res == head && l) res = l;
            if(!l) break;
            ListNode* remainingList = l->next;
            l->next = nullptr;
            auto end = reverse(ptr);
            end->next = remainingList;
            if(prevEnd) prevEnd->next = l;
            prevEnd = end;
            ptr = remainingList;
        }
        return res;
    }
};