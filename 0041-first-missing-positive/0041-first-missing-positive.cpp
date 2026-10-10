class Solution {
public:
    bool isValid(int v,int n){
        if(v>0 && v<n+1) return 1;
        return 0;
    }
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(!isValid(nums[i],nums.size())) nums[i]=nums.size()+1;
        }
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])==nums.size()+1) continue;
            else if(nums[i]>0){
                nums[nums[i]-1]=-1*abs(nums[nums[i]-1]);
            }
            else{
                nums[-1*nums[i]-1]=-1*abs(nums[-1*nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return i+1;
        }
        return nums.size()+1;
    }
};