class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> due;
        vector<int> result(nums.size()-k+1);
        for(int i=0;i<nums.size();i++){
            while(!due.empty() && nums[i]>nums[due.back()]) due.pop_back();
            if(!due.empty() && i-k>=due.front()) due.pop_front();
            due.push_back(i);
            if(i>=k-1) result[i-k+1]=(nums[due.front()]);
        }
        return result;
    }
};