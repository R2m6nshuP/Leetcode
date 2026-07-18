class Solution {
public:
    bool isPalin(string &s){
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto &i : words){
            if(isPalin(i)) return i;
        }
        return "";
    }
};