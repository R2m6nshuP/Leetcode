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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        bool counting =0;
        while(head){
            bool present = s.count(head->val);
            if(present && !counting) {
                ans++;
                counting=1;
            }
            if(!present){
                counting=0;
            }
            head=head->next;
        }
        return ans;
    }
};