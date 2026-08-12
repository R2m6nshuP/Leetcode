class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<1) return 0;
        if(num%10==2 || num%10==3 || num%10==7 || num%10==8) return 0;
        int l=1;
        int r=num;
        long long mid;
        int ans=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mid*mid<=num){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans*ans==num;
    }
};