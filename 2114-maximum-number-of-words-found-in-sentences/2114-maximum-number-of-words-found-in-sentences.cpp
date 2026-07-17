class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(auto s: sentences){
            int cnt=0;
            for(auto i : s){
                if(i==' ') cnt++;
            }
            ans=max(ans,cnt+1);
        }
        return ans;
    }
};