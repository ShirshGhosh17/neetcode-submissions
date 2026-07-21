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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* h1 = l1;
        ListNode* h2 = l2;

        int carry = 0;

        while(h1 != NULL && h2 != NULL){
            int sum = h1->val+h2->val+carry;
            int dig = sum%10;
            carry = sum/10;

            ListNode* newnode = new ListNode(dig);
            temp->next = newnode;
            h1 = h1->next;
            h2 = h2->next;
            temp = temp->next;
        }

        while(h1 != NULL){
            int sum = h1->val+carry;
            int dig = sum%10;
            carry = sum/10;

            ListNode* newnode = new ListNode(dig);
            temp->next = newnode;
            h1 = h1->next;
            temp = temp->next;
        }

        while(h2 != NULL){
            int sum = h2->val+carry;
            int dig = sum%10;
            carry = sum/10;

            ListNode* newnode = new ListNode(dig);
            temp->next = newnode;
            h2 = h2->next;
            temp = temp->next;
        }

        if(carry != 0) temp->next = new ListNode(carry);

        return dummy->next;
    }
};
