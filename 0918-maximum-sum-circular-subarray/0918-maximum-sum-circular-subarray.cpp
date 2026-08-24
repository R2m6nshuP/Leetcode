class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=nums[0];
        int ans=99999;
        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            curr=min(nums[i],curr+nums[i]);
            ans=min(ans,curr);
        }
        ans=min(ans,curr);
        ans=sum-ans;
        curr=nums[0];
        sum=-99999;
        for(int i=1;i<nums.size();i++){
            curr=max(nums[i],curr+nums[i]);
            sum=max(sum,curr);
        }
        sum=max(sum,curr);
        if(!ans) return sum;
        return max(sum,ans);
    }
};