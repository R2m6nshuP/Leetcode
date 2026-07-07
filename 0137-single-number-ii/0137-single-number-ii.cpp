class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> pow(32);
        for(int i=0;i<32;i++){
        for(auto num: nums){
            if((num>>i)&1) pow[i]++;
        }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(pow[i]%3==1) ans+=(1<<i);
        }
        return ans;
    }
};