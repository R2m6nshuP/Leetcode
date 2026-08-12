class Solution {
public:
    string conv(int n){
        if(n<=9) return string(1,n+'0');
        return string(1,'a'+n-10);
    }
    string toHex(int n) {
        string ans="";
        if(n==0) return "0";
        unsigned int num=n;
        while(num){
            ans=conv(num%16)+ans;
            num/=16;
        }
        return ans;
    }
};