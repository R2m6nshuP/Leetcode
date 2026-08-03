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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return head;
        ListNode* temp=head;
        int sum=0;
        while(temp->next){
            if(temp->next->val==0){
                temp->next->val=sum;
                sum=0;
                temp=temp->next;
            }
            else{
                sum+=temp->next->val;
                temp->next=temp->next->next;
            }
        }
        return head->next;
    }
};