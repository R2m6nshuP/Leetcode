class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=(start^goal);
        int ans=0;
        while(cnt){
            ans+=cnt%2;
            cnt/=2;
        }
        return ans;
    }
};