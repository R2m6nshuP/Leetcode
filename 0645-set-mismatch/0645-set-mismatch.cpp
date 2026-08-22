class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int sum=0;
       int both=0;
       for(auto i : nums){
        sum+=i;
        both^=i;
       }
       for(int i=1;i<=nums.size();i++) both^=i;
       int setBits=0,notsetBits=0;
       for(auto i : nums) {
            if(i & (both&(~both+1))) setBits^=i;
            else notsetBits^=i;
       }
       for(int i=1;i<=nums.size();i++) {
        if(i &(both&(~both+1))) setBits^=i;
        else notsetBits^=i;
       }
       vector<int> ans;
        if(sum<(nums.size()*(nums.size()+1))/2) {
            ans.push_back(min(setBits,notsetBits));
            ans.push_back(max(setBits,notsetBits));
        }
        else {
            ans.push_back(max(setBits,notsetBits));
            ans.push_back(min(setBits,notsetBits));
        }
    return ans;
    }

};