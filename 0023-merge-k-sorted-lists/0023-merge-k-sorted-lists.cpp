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
    ListNode* merger(ListNode* list1,ListNode* list2){
        if(!list1) return list2;
        else if(!list2) return list1;
        ListNode* dumpy=new ListNode (-1);
        ListNode* temp=dumpy;
        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1) temp->next=list1;
        if(list2) temp->next=list2;
        return dumpy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        if(lists.size()==1) return lists[0];
        vector<ListNode*> ans;
        for(int i=0;i<lists.size();i+=2){
            if(i<lists.size()-1) ans.push_back(merger(lists[i],lists[i+1]));
            else ans.push_back(lists[i]);
        }
        return mergeKLists(ans);
    }
};