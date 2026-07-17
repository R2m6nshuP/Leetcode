class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans(numCourses);
        if(prerequisites.empty()){
            for(int i=0;i<numCourses;i++){
                ans[i]=i;
            }
            return ans;
        }
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> isPrerq(numCourses);
        for(auto &v: prerequisites){
            isPrerq[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int curr=q.front();
            ans[cnt]=curr;
            cnt++;
            q.pop();
            for( auto &neigh : isPrerq[curr]){
                inDegree[neigh]--;
                if(!inDegree[neigh]){
                    q.push(neigh);
                }
            }
        }
    if(cnt!=numCourses){
        ans.clear();
    }
    return ans;
    }
};