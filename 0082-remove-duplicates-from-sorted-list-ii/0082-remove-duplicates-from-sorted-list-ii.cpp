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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dumpy=new ListNode(-1);
        ListNode* temp=dumpy;
        while(head){
            if(head->next && head->val==head->next->val) {
                while(head->next && head->val==head->next->val) head=head->next;
                head=head->next;
            }
            else{
                ListNode* str=head->next;
                temp->next=head;
                head->next=NULL;
                head=str;
                temp=temp->next;
            }
        }
        return dumpy->next;
    }
};