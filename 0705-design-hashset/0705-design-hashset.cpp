class MyHashSet {
public:
    struct Node{
        int val;
        Node* next=NULL;
        Node(int v,Node* n){
            val=v;
            next=n;;
        }
        Node(int v) {
            val=v;
        }
    };
    Node* head;
    MyHashSet() {
        head=NULL;
    }
    
    void add(int key) {
        if(!contains(key)) head=new Node(key,head);
    }
    
    void remove(int key) {
        Node*  curr=head;
        if(!head) return;
        if(curr->val==key) {
            Node* temp=curr;
            head=curr->next;
            delete temp;
            return;
        }
        while(curr->next){
            if(curr->next->val==key){
                Node* temp=curr->next;
                curr->next=temp->next;
                delete temp;
                return;
            }
            curr=curr->next;
        }
    }
    
    bool contains(int key) {
        Node* curr=head;
        while(curr){
            if(curr->val==key) return 1;
            curr=curr->next;
        }
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */