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
    pair<ListNode*,ListNode*> reverser(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp){
            ListNode* store=temp->next;
            temp->next=prev;
            prev=temp;
            temp=store;
        }
        pair<ListNode*,ListNode*> ans={prev,head};
        return ans;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l=head;
        ListNode* r=head;
        ListNode* storer=r->next;
        while(right-left){
            r=r->next;
            storer=r->next;
            right--;
        }
        ListNode* storel=NULL;
        int i=1;
        while(i!=left){
            storel=l;
            l=l->next;
            r=r->next;
            storer=r->next;
            i++;
        }
        r->next=NULL;
        pair<ListNode*,ListNode*> ans=reverser(l);
        ans.second->next=storer;
        if(!storel) return ans.first;
        storel->next=ans.first;
        return head; 
    }
};