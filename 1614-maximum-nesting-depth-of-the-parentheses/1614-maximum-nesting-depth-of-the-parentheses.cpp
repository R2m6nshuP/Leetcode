class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int cnt=0;
        for( auto i : s){
            if(i=='(') cnt++;
            else if(i==')') {
                ans=max(ans,cnt);
                cnt--;
            }
            else continue;
        }
        ans=max(cnt,ans);
        return ans;
        
    }
};