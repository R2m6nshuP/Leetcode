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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        ListNode* dumpy=new ListNode(-1);
        ListNode* tail=dumpy;
        while(temp ){
            if(temp->val!=val){
                ListNode* store=temp->next;
                tail->next=temp;
                tail=temp;
                tail->next=NULL;
                temp=store;
            }
            else temp=temp->next;
        }
        return dumpy->next;
    }
};