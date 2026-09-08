class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> pq{0};
        vector<vector<int>> ans;
        vector<pair<int,int>> points;
        for(auto v : buildings){
            points.push_back({v[0],-v[2]});
            points.push_back({v[1],v[2]});
        }
        sort(points.begin(), points.end());
        int ongoingH=0;
        for(int i=0;i<points.size();i++){
            int pt=points[i].first;
            int currH=points[i].second;
            if(currH>0){
                auto it = pq.find(currH);
                pq.erase(it);
            }
            else{
                currH*=-1;
                pq.insert(currH);
            }
            int currtop=*(pq.rbegin());
            if(currtop!=ongoingH){
                ongoingH=currtop;
                ans.push_back({pt,currtop});
            }

        }
        return ans;
    }
};