class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int m=heightMap.size();
        int n=heightMap[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,0));
        priority_queue<pair<int,pair<int,int>>,
               vector<pair<int,pair<int,int>>>,
               greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1) || (j==0 || j==n-1)) {
                    pq.push({heightMap[i][j],{i,j}});
                    visited[i][j]=1;
                }
            }
        }
        int hei=-1;
        int ans=0;
        while(!pq.empty()){
            auto tp=pq.top();
            int h=tp.first;
            int i=tp.second.first;
            int j=tp.second.second;
            pq.pop();
            if(i+1<m && !visited[i+1][j]) {
                pq.push({heightMap[i+1][j],{i+1,j}});
                visited[i+1][j]=1;
            }
            if(i-1>=0 && !visited[i-1][j]) {
                pq.push({heightMap[i-1][j],{i-1,j}});
                visited[i-1][j]=1;
            }
            if(j-1>=0 && !visited[i][j-1]) {
                pq.push({heightMap[i][j-1],{i,j-1}});
                visited[i][j-1]=1;
            }
            if(j+1<n && !visited[i][j+1]) {
                pq.push({heightMap[i][j+1],{i,j+1}});
                visited[i][j+1]=1;
            }
            ans+=max(0,hei-heightMap[i][j]);
            hei=max(hei,h);
        }
        return ans;
    }
};