class Solution {
public:
    int jump(vector<int>& nums) {
        int can=0;
        int i=0;
        int ans=0;
        while(can<nums.size()-1){
        int sum=0;
        for(i;i<=can;i++){
           sum=max(sum,i+nums[i]); 
        }
        can=sum;
        ans++;
        }
        return ans;
    }
};