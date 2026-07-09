class Solution {
public:
    int appendCharacters(string s, string t) {
        int l=0;
        int r=0;
        while(l<s.size()){
            if(s[l]==t[r]){
                r++;
            }
            l++;
        }
        return t.size()-r;
    }
};