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
    ListNode* revll(ListNode* head){
        ListNode* ptr=head;
        ListNode* prev=NULL;
        while(ptr){
            ListNode* temp=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* dump= new ListNode(-1);
        ListNode* temp=dump;
        ListNode* ptr=head;
        int i=0;
        ListNode* start;
        while(ptr){
            if(i<k-1) {
                if(i==0){
                    start=ptr;
                }
                i++;
                ptr=ptr->next;
            }
            else{
                ListNode* newnode=ptr->next;
                ptr->next=NULL;
                temp->next=revll(start);
                temp=start;
                start=NULL;
                i=0;
                ptr=newnode;
            }
        }
        temp->next=start;
        return dump->next;
    }
};