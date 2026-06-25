class Solution {
public:
    double myPow(double x,int n){
        if(n==0) return 1;
        if(n==1) return x;
        if(x==1) return 1;
        if(x==-1) return n%2==0 ? 1: -1;
        if(n>0){
        int half=n/2;
        double ans=myPow(x,half);
        return ans*ans*myPow(x,n%2);
        }
        else{
            if(n==INT_MIN) return 0;
            return 1/myPow(x,-n);
        }


    }
};