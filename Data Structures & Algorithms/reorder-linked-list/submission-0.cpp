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
    void reorderList(ListNode* head) {
        ListNode* ptr1,*ptr2;
        if(!head || !head->next) return;
        ptr1 = head, ptr2 = head->next;
        while(ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = nullptr;
        ptr2->next = head->next;
        head->next = ptr2;

        reorderList(head->next->next);
    }
};
