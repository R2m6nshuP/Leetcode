class Solution {
public:
    int arrangeCoins(int n) {
    int l=1;
    int r=n;
    long long mid;
    long long multi;
    int ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        multi=(mid*(mid+1))/2;
        if(multi<=n){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
    }
};