class Solution {
public:
    int countDigits(int num) {
        int cnt=0;
        int copy=num;
        while(num){
            if(copy%(num%10)==0) cnt++;
            num/=10;
        }
        return cnt;
    }
};