class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return 0;
        int cnt=1;
        unordered_set<char> se;
        unordered_map<char,char> m;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]=='\0') {
                if(se.count(t[i])) return 0;
                m[s[i]]=t[i];
                se.insert(t[i]);
            }
            else if(m[s[i]]==t[i]) continue;
            else return 0;
            
        }
         
        return 1;
    }
};