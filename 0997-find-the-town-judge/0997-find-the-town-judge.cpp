class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> tn(n+1,0);
        for(auto &v: trust){
            tn[v[1]]++;
            tn[v[0]]=-1;
        }
        for(int i=1;i<=n;i++){
            if(tn[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};