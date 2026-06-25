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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* even=head->next;
        ListNode* odd=head;
        ListNode* evenstart=head->next;
         
        ListNode* ptr=head->next;
        head->next=NULL;
        odd->next=NULL;
        int cnt=2;
        while(ptr){
            ListNode* next=ptr->next;
            ptr->next=NULL;
            if(cnt%2==1){
                odd->next=ptr;
                odd=ptr;
                odd->next=nullptr;
            }
            else{
                if(cnt==2) {even=ptr; evenstart=ptr;}
                else even->next=ptr;
                even=ptr;
                even->next=nullptr;
            }
            ptr=next;
            cnt++;
        }
        odd->next=evenstart;
        return head;
    }
};