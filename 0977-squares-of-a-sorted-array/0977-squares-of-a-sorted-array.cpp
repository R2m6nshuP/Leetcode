class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l=0;
        int r=nums.size()-1;
        int ptr=nums.size()-1;
        while(ptr>=0){
            if(abs(nums[l])>abs(nums[r])){
                ans[ptr]=nums[l]*nums[l];
                ptr--;
                l++;
            }
            else{
                ans[ptr]=nums[r]*nums[r];
                ptr--;
                r--;
            }
        }
        return ans;
    }
};