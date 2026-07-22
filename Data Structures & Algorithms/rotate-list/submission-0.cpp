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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;

        if(head == NULL || head->next == NULL) return head;

        while(temp != NULL){
            temp = temp->next;
            count++;
        }

        k=k%count;
        if(k==0) return head;

        int step = count-k-1;
        temp = head;

        while(step--){
            temp = temp->next;
        }

        ListNode* newhead = temp->next;

        temp->next = NULL;
        ListNode* p = newhead;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = head;
        return newhead;
    }
};