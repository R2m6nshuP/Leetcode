class Solution {
public:
    int reverseBits(int n) {
        vector<bool> pow(32,0);
        for(int i=0;i<32;i++){
            pow[i]=1&(n>>i);
        }
        int ans=0;
        for(int i=31;i>=0;i--){
            ans+=pow[31-i]*(1<<i);
        }
    return ans;
    }
};