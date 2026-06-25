class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.reserve(1 << nums.size());
        int p= (1<<nums.size());
        for(int i=0;i<p;i++){
            vector<int> ai;
            int j=0;
            while( (1<<j)<= i){
                if(i&(1<<j)) ai.push_back(nums[j]);
                j++;
            }
            ans.push_back(ai);
        }
        return ans;

        
    }
};