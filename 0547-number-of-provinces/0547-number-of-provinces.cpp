class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                visited[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[node][j]){
                            if(!visited[j]){
                                visited[j]=1;
                                q.push(j);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};