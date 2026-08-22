class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=-1;
        int cnt=0;
        for(auto i : nums){
            if(i){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};