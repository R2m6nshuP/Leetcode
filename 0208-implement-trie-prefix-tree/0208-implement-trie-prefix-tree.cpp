class Trie {
public:
    struct node{
        bool fullflag=0;
        map<char,node*> child;
        string label;
    };
    int common(string &s,string &t,int i){
        int l=0;
        while(l<t.size() && i+l<s.size() && t[l]==s[i+l]) {l++;}
        return l;
    }
    bool matches(string &s,int pos,node* ch){
        return common(s,ch->label,pos)==ch->label.size();
    }
    node* root;
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* p=root;
        int k=0;
        while(1){
            if(k>=word.size()){
                p->fullflag=1;
                return;
            }
            if(!p->child.count(word[k])){
                auto n=new node();
                n->label=word.substr(k);
                n->fullflag=1;
                p->child[word[k]]=n;
                return;
            }
            node* ch=p->child[word[k]];
            int m=common(word,ch->label,k);
            if(m<ch->label.size()){
                auto n=new node();
                n->label=ch->label.substr(0,m);
                ch->label=ch->label.substr(m);
                p->child[word[k]]=n;  
                n->child[ch->label[0]]=ch; //fix
                ch=n;
            }
            {
                k+=m;
                p=ch;
            }
        }
    }
    
    bool search(string word) {
        node* p=root;
        int k=0;
        while(k<word.size()){
            if(k==word.size()) break;
            if(!p->child.count(word[k])){
                return 0;
            }
            node* ch=p->child[word[k]];
            if(!matches(word,k,ch)) return 0;
            k+=ch->label.size();
            p=ch;
        }
        return p->fullflag;
        
    }
    
    bool startsWith(string prefix) {
        node* p=root;
        int k=0;
        while(k<prefix.size()){
            if(!p->child.count(prefix[k])){
                return 0;
            }
            node* ch=p->child[prefix[k]];
            int m=common(prefix,ch->label,k);
            if(m!=min(ch->label.size(),prefix.size()-k)) return 0;
            k+=m;
            p=ch;
        }
        return 1;   
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */