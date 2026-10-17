class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(nums[i]!=(q.size()%2 ? 0 : 1)){
                cnt++;
                q.push(i+k-1);
            }
            while ( !q.empty() && q.front()<=i) q.pop();
        }
        return q.empty() ? cnt : -1;
    }
};