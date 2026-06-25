class Solution {
public:
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<bool> prime(n,1);
        prime.reserve(n);
        prime[0]=0;
        prime[1]=0;
        int i=2;
        if(prime[i]){
                int j=i*2;
                while(j<n){
                    prime[j]=0;
                    j+=i;
                }
            }
        for(i=3;i*i<=n;i+=2){
            if(prime[i]){
                int j=i*2;
                while(j<n){
                    prime[j]=0;
                    j+=i;
                }
            }
        }
        int ans=0;
        if( n> 2 && prime[2]){
                ans++;
            }
        for(int i=3;i<n;i+=2){
            if(prime[i]){
                ans++;
            }
        }
        return ans;
    }
};