class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.size()!=t.size()) return 0;
    int freq[26]={0};
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;

    }
    for(int i=0;i<s.size();i++){
        freq[t[i]-'a']--;
        
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0) return 0;
        
    }
    return 1;
    }
};