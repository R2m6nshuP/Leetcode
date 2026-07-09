class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int l=0;
        sort(nums.begin(),nums.end());
        int r=nums.size()-1;
        int ans=0;
        while(l<=r){
            if(nums[l]+nums[r]>=target){
                r--;
            }
            else{
                ans+=r-l;
                l++;
            }
        }
        return ans;
    }
};