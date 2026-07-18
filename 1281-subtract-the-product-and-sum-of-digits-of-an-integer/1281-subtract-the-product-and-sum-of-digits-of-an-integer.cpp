class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro=1;
        int sum=0;
        while(n){
            int i=n%10;
            pro*=i;
            sum+=i;
            n/=10;
        }
        return pro-sum;
    }
};