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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dumpy=new ListNode(-1);
        dumpy->next=head;
        ListNode* tail=dumpy;
        while(tail->next && tail->next->next){
            ListNode* f=tail->next;
            ListNode* s=f->next;
            f->next=s->next;
            s->next=f;
            tail->next=s;
            tail=f;
        }
        return dumpy->next;
    }
};