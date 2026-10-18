class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {   
        int ans=INT_MIN ;
        priority_queue<pair<int,int>> pq;
        pq.push({-points[0][0]+points[0][1],points[0][0]});
        for(int i=1;i<points.size();i++){
            int sum=points[i][0]+points[i][1];
            while(!pq.empty() && points[i][0]-pq.top().second>k) pq.pop();
            if(!pq.empty()) ans=max(ans,sum+pq.top().first);
            pq.push({-points[i][0]+points[i][1],points[i][0]});
        }
        return ans;
        }
        

};