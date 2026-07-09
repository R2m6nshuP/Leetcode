class Solution {
public:
    bool normalPalindrome(string s,int l,int r) {
        // int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
               return 0;
            }
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        int cnt=0;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else if(cnt && s[l]!=s[r]){
                return 0;
            }
            else{
                if(normalPalindrome(s.substr(l+1,r-l),0,r-l-1)) l++;
                else r--;
                cnt=1;
            }
        }
        return 1;
    }
};