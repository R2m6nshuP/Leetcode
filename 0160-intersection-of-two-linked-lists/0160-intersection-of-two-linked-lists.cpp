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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* ptra,ptrb;
        ListNode* ptra=headA;
        ListNode* ptrb=headB;
        
        int A=0;
        int B =0;
        while(ptra){
            A++;
            ptra=ptra->next;
        }
        while(ptrb){
            B++;
            ptrb=ptrb->next;
        }
        ptra=headA;
        ptrb=headB;
        int cnt;
        if(A==B);
        else {
            cnt=abs(A-B);
            if(A>B){
                while(cnt){
                    ptra=ptra->next;
                    --cnt;
                }
            }
            else{
                while(cnt){
                    ptrb=ptrb->next;
                    --cnt;
                }
            }
        }
        while(ptra){
            if(ptra==ptrb) return ptra;

            ptra=ptra->next;
            ptrb=ptrb->next;
        }
        return NULL;

    }
};