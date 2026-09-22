class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &n : nums) mp[n]++;
        priority_queue<pair<int,int>> pq;
        for(auto &[n,fr] : mp) {
            pq.push({fr,n});
        } 
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};