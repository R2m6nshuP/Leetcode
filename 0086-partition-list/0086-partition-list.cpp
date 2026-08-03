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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *l=NULL,*r=NULL,*lt,*rt;
        while(head){
            if(head->val<x){
                if(!l){
                    l=head;
                    lt=head;
                }
                else{
                lt->next=head;
                lt=lt->next;
                }
            }
            else{
                if(!r){
                    r=head;
                    rt=head;
                }
                else{
                    rt->next=head;
                    rt=rt->next;
                }
            }
            head=head->next;
        }
        if(!l) return r ;
        lt->next=r;
        if(r) rt->next=NULL;
        return l;
    }
};