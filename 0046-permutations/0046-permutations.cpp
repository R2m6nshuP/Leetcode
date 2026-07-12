class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int> &poss,vector<int> &nums,vector<bool> &taken){
        if(poss.size()==nums.size()) {
            ans.push_back(poss);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(taken[i]) continue;
            taken[i]=1;
            poss.push_back(nums[i]);
            helper(ans,poss,nums,taken);
            poss.pop_back();
            taken[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> taken(nums.size(),0);
        vector<vector<int>> ans;
        vector<int> poss;
        helper(ans,poss,nums,taken);
        return ans;
    }
};