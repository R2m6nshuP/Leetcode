class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        int sign=1;
        if(num<0) {
            sign=-1;
            num=-num;
        }
        string ans="";
        while(num){
            ans=string(1,num%7+'0')+ans;
            num/=7;
        }
        if(sign<0) ans="-"+ans;
        return ans;
    }
};