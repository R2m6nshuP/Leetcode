/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* ptr=head;
        unordered_map<Node*,Node* > mp;
        Node* prev=NULL;
        Node* newhead;
        while(ptr){
            Node* newcopy = new Node(ptr->val);
            if(prev) prev->next=newcopy;
            else newhead=newcopy;
            prev=newcopy;
            mp[ptr]=newcopy;
            ptr=ptr->next;
        }
        prev->next=NULL;
        ptr=head;
        prev=newhead;
        while(ptr){
            if(ptr->random) prev->random=mp[ptr->random];
            else prev->random=NULL;
            ptr=ptr->next;
            prev=prev->next;
        }
        return newhead;

    }
};