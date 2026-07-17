class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return 1;
        vector<vector<int>> adj(numCourses);
        vector<int> prereq(numCourses,0);
        for(auto v: prerequisites){
            prereq[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        int cnt=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(prereq[i]==0){
                q.push(i);
            }
            }
        while(!q.empty()){
                int node=q.front();
                cnt++;
                q.pop();
                for(auto j: adj[node]){
                    prereq[j]--;
                    if(prereq[j]==0){
                        q.push(j);
                    }
                }
        }
        return cnt==numCourses;
    }
};