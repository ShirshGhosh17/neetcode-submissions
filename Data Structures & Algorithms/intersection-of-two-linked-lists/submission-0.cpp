/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* h1 = headA;
        ListNode* h2 = headB;

        int cnt1 = 0;
        int cnt2 = 0;
        while(h1 != NULL){
            h1 = h1->next;
            cnt1++;
        }

        while(h2 != NULL){
            h2 = h2->next;
            cnt2++;
        }

        int steps = abs(cnt1-cnt2);
        h1 = headA;
        h2 = headB;

        if(cnt1 > cnt2){
            while(steps--){
                h1=h1->next;
            }
        }
        else{
            while(steps--){
                h2=h2->next;
            }
        }

        while(h1!=NULL && h2!=NULL){
            if(h1 == h2){
                return h1;
                break;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        return NULL;
    }
};