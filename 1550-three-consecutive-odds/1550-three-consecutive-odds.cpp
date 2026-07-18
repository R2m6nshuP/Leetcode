class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(auto &i: arr){
            if(i&1) {
                cnt++;
                if(cnt==3) return 1;
            }
            else cnt=0;
        }
        return 0;
    }
};