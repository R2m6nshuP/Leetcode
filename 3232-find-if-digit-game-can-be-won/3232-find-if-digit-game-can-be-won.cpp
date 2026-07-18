class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum=0;
        for(auto &i : nums){
            if(i>=10) sum+=i;
            else sum-=i;
        }
        return sum;
    }
};