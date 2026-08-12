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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parthead(k);
        int carry;
        int j;
        ListNode* temp=head;
        int n=0;
        while(temp) {
            n++;
            temp=temp->next;
        }
        carry=n%k;
        for(int i=0;i<k;i++){
            j=0;
            if(carry>0){
                j=1;
                carry--;
            }
            ListNode* tail=NULL;
            for(int l=0;l<(n/k)+j;l++){
                if(!tail){
                    parthead[i]=head;
                    tail=head;
                    head=head->next;
                    tail->next=NULL;
                }
                else{
                    tail->next=head;
                    head=head->next;
                    tail=tail->next;
                    tail->next=NULL;
                }
            }
        }
        return parthead;
    }
};