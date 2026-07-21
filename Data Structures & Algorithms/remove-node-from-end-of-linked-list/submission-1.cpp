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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        cout<<count;
        if(count == n) return head->next;

        int k = count-n+1;
        
        count = 0;
        temp = head;


        while(count < k-2){
            temp=temp->next;
            count++;
        }

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete(del);
        return head;
    }
};
