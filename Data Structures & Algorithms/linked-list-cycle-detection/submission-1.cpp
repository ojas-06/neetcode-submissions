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
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        ListNode* slow = head, *fast = head;
        do{
            if(!fast->next || !fast->next->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        return true;
    }
};
