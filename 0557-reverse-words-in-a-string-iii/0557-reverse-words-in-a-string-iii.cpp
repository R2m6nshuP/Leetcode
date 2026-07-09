class Solution {
public:
    string reverseWords(string s) {
    int l=0;
    int r=1;
    while(r<s.size()){
        if(s[r]!=' ') r++;
        else{
            reverse(s.begin()+l,s.begin()+r);
            while(s[r]==' ') r++;
            l=r;

        }
    }
    reverse(s.begin()+l,s.begin()+r);
    return s;
    }
};