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
    ListNode* headll=NULL;
    Solution(ListNode* head) {
        srand(time(0));
        headll=head;
    }
    
    int getRandom() {
        int len=0;
        ListNode* temp=headll;
        while(temp){
            len++;
            temp=temp->next;
        }
        len=rand()%len+1; 
        temp=headll;
        while(--len){
            temp=temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */