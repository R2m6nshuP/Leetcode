class Solution {
public:
    int mySqrt(int x) {
        if(!x) return 0;
        if(x==1) return 1;
        int l=1;
        int r=x;
        int ans = -1;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long mul=(long long)mid*mid;
            if(mul<=x){
                ans = mid;
                l = mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};