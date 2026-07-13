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
    ListNode* reversell(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* prev=NULL;
        while(head){
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next ) return head;
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++; 
        }
        k%=cnt;
        cnt=0;
        if(k==0) return head;
        head=reversell(head);
        ListNode* dump= new ListNode(-1);
        
       
        ListNode* prev=NULL;
        temp=head;
        while(cnt<k){
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        prev->next=NULL;
        dump->next=reversell(head);
        head->next=reversell(temp);
        return dump->next;

    }
};