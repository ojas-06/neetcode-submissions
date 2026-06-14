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
    int carry = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) {
            if(carry) return new ListNode(carry);
            return nullptr;
        }
        if(!l1) {
            l2->val += carry;
            if(l2->val >= 10) {
                l2->val %= 10;
                carry = 1;
            }
            else carry = 0;
            l2->next = addTwoNumbers(nullptr, l2->next);
            return l2;
        }
        if(!l2) {
            l1->val += carry;
            if(l1->val >= 10){
                l1->val %= 10;
                carry = 1;
            }
            else carry = 0;
            l1->next = addTwoNumbers(l1->next,nullptr);
            return l1;
        }
        ListNode* L = new ListNode((l1->val + l2->val + carry) % 10);
        carry = (l1->val+l2->val+carry > 9)? 1 : 0;
        L->next = addTwoNumbers(l1->next, l2->next);
        return L;
    }
};
