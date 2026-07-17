class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        int ele=0;
        for(auto &i : nums){
            sum+=i;
            while(i){
                ele+=i%10;
                i/=10;
            }
        }
        return abs(sum-ele);
    }
};