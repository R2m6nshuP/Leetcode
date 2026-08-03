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
    ListNode* reverser(ListNode* head){
        if(!head) return head;
        ListNode* prev=NULL;
        ListNode* tmp;
        while(head){
            tmp=head->next;
            head->next=prev;
            prev=head;
            head=tmp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head) return head;
        head=reverser(head);
        ListNode* temp=head;
        while(temp->next){
            if(temp->next->val<temp->val){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return reverser(head);
    }
};