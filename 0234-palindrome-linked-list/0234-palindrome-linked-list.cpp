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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;
        ListNode* slow;
        ListNode* fast;
        slow=head;
        fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=slow;
        ListNode* prev=NULL;
        while(head2){
        ListNode* front= head2->next;
        head2->next=prev;
        prev=head2;
        head2=front;
        }
        head2=prev;
        while(head2){
            if(head->val!=head2->val) return 0;
            head=head->next;
            head2=head2->next;
        }
        return 1;
    }
};