class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canJump=0;
        for(int  j=0;j<=canJump;j++){
            if(canJump>=nums.size()-1) return 1;
            canJump=max(canJump,j+nums[j]);
        }
        return canJump>=nums.size()-1;
    }
};