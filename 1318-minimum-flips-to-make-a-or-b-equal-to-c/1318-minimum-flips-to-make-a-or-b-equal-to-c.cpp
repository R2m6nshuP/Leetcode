class Solution {
public:
    int minFlips(int a, int b, int c) {
    //  int i=0;
     int cnt=0;
     while(a || b || c){
        if((((a&1)|(b&1))&(c&1))==0) {
           if(c&1) {
            cnt++;
           }
           else {
            cnt+=(a&1) + (b&1);
           }
        }
a >>= 1;
b >>= 1;
c >>= 1;
     }
     return cnt;   
    }
};