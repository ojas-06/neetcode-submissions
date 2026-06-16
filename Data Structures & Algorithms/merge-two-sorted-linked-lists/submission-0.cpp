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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr1 = list1, *ptr2 = list2; 
        ListNode* head = nullptr,* end = nullptr;
        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                if(!head) {head = ptr1;end = ptr1;}
                else {
                    end->next = ptr1;
                    end = end->next;
                }
                ptr1 = ptr1->next;
                end->next = nullptr;
            }
            else{
                if(!head) {head = ptr2;end = ptr2;}
                else {
                    end->next = ptr2;
                    end = end->next;
                }
                ptr2 = ptr2->next;
                end->next = nullptr;
            }
        }
        if(!head) {
            if(ptr1) return ptr1;
            return ptr2;
        }
        if(ptr1) end->next = ptr1;
        else if(ptr2) end->next = ptr2;
        return head;
    }
};
