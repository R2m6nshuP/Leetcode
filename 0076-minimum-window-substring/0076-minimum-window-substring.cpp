class Solution {
public:
    // bool sat(unordered_map<char,int> &s,unordered_map<char,int> &mp){
    //     for(auto &[ch,fq] : mp){
    //         auto it=s.find(ch);
    //         if(it==s.end() || it->second<fq) return 0;
    //     }
    //     return 1;
    // }
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        vector<int> need(128,0);
        for(auto k : t) need[k]++;
        int counter=t.size();
        int d=INT_MAX;
        int head;
        while(j<s.size()){
            if(need[s[j++]]-->0) counter--;
            while(counter==0){
                if(d>j-i){
                    // ans=s.substr(i=head,(j-i));
                    d=j-i;
                    head=i;
                }
                if(need[s[i++]]++==0) counter++;
            }
        }
        return d!=INT_MAX ? s.substr(head,d) : "";
    }
};