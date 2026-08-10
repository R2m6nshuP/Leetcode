class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<pair<int,int>> leftSandwiches(2,{0,0});
        queue<int> q(students.begin(),students.end());
        int j=0;
        for(auto i : sandwiches) leftSandwiches[i].first++;
        for(auto i : students) leftSandwiches[i].second++;
        while(!q.empty()){
            if(leftSandwiches[sandwiches[j]].second==0) break;
            else if(sandwiches[j]==q.front()){
                leftSandwiches[q.front()].first--;
                leftSandwiches[q.front()].second--;
                q.pop();
                j++;
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
        return q.size();
    }
};