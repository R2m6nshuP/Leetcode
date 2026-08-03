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
        ListNode* str;
        while(head){
            str=head->next;
            head->next=prev;
            prev=head;
            head=str;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revhead=reverser(slow->next);
        slow->next=NULL;
        fast=head;
        while(fast && revhead){
            ListNode* str=fast->next;
            fast->next=revhead;
            ListNode* str2=revhead->next;
            revhead->next=str;
            revhead=str2;
            fast=str;
        }
    }
};