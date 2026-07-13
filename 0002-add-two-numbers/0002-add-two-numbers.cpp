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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dumpy=new ListNode(-1);
        ListNode* temp=dumpy;
        int carry=0;
        while(l1 || l2){
            int sum=0;
            sum+=carry;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            ListNode* newnode = new ListNode(sum%10);
            carry=sum/10;
            temp->next=newnode;
            temp=newnode;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry){
           ListNode* newnode = new ListNode(carry);
            temp->next=newnode;
            temp=newnode; 
        }
        return dumpy->next;
    }
};