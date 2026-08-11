/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* dumpy=new Node(-1);
        Node* temp=dumpy;
        stack<Node*> st;
        st.push(head);
        while(!st.empty()){
            Node* str=st.top();
            st.pop();
            temp->next=str;
            str->prev=temp;
            temp=temp->next;
            if(str->next) st.push(str->next);
            if(str->child) st.push(str->child);
            temp->child=NULL;
        }
        dumpy->next->prev=NULL;
        return dumpy->next;
    }
};