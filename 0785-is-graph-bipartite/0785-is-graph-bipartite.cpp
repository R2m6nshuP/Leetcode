class Solution {
public:
    bool helper(vector<vector<int>>& graph,int c,vector<bool>&vis,vector<bool>&color,int i){
        vis[i]=1;
        color[i]=c;
        for(auto u: graph[i]){
            if(vis[u]  && color[u]==color[i]) return 0;
            if(vis[u]) continue;
            if(!helper(graph,1-c,vis,color,u)) return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(),0),color(graph.size());
        for(int i=0;i<graph.size();i++){
            if(vis[i]) continue;
            if(!helper(graph,0,vis,color,i)) return false;
        }
        return 1;
    }
};