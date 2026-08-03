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
    ListNode* doubleIt(ListNode* head) {
        if(!head) return head;
        head=reverser(head);
        ListNode* temp=head;
        int carry=0;
        while(temp){
            carry+=temp->val*2;
            temp->val=carry%10;
            carry/=10;
            temp=temp->next;
        }
        if(carry){
            return head=new ListNode(carry,reverser(head));
        }
        else return reverser(head);
    }
};