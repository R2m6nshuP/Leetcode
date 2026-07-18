class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto &v : accounts){
            int sum=0;
            for(auto &m : v){
                sum+=m;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};