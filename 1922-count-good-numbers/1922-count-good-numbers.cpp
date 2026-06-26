class Solution {
public:
    long long fun(int n,long long p,long long &mod){
        if(p==0) return 1;
        if(p==1) return n%mod;
        long long half=(fun(n,p/2,mod)%mod);
        long long ans = (half*half*fun(n,p%2,mod))%mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long mod=1000000007;
        // n%=mod;
        return (fun(4,n/2,mod)*fun(5,n-n/2,mod))%mod;
        
    }
};