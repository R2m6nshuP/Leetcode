class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            int i=tp.first.first;
            int j=tp.first.second;
            if(grid[i][j]==1){
                cnt--;
                t=tp.second;
            }
            grid[i][j]=0;
            if(i+1<n && grid[i+1][j]==1){
                q.push({{i+1,j},t+1});
            }
            if(i-1>=0 && grid[i-1][j]==1){
                q.push({{i-1,j},t+1});
            }
            if(j+1<m && grid[i][j+1]==1){
                q.push({{i,j+1},t+1});
            }
            if(j-1>=0 && grid[i][j-1]==1){
                q.push({{i,j-1},t+1});
            }
        }
        return cnt==0 ? t : -1;
    }
};