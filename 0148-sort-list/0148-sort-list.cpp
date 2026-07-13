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
    ListNode* merge(ListNode* l,ListNode* r){
        ListNode dump(-1);
        ListNode* temp=&dump;
        while(l  && r ){
            if(l->val < r->val){
                temp->next=l;
                temp=l;
                l=l->next;
            }
            else{
                temp->next=r;
                temp=r;
                r=r->next;
            }
        }
        if(l) temp->next=l;
        else temp->next=r;
        return dump.next;
    }
    ListNode* findMid(ListNode* head){
        ListNode* slow;
        slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* ms(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* mid=findMid(head);
        ListNode* leftHead=head;
        ListNode* rightHead=mid->next;
        mid->next=NULL;
        leftHead=ms(leftHead);
        rightHead=ms(rightHead);
        return merge(leftHead,rightHead);
    }
    ListNode* sortList(ListNode* head) {
        return ms(head);
    }
};