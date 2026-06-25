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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=head;
        int cnt=0;
        while(ptr){
            cnt++;
            ptr=ptr->next;
        }
        ptr=head;
        n=cnt-n+1;
        cnt=1;
        ListNode* prev=nullptr;
        while(ptr){
            if(cnt==n){
                if(!prev) head=head->next;
                else prev->next=ptr->next;
                break;
            }
            else{
                cnt++;
                prev=ptr;
                ptr=ptr->next;
            }

        }
        return head;

        
    }
};