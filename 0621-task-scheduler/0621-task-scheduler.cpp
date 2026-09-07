class Solution {
public:
    bool cando(unordered_map<char,int> &lasttime,int i,char t,int k){
        return (i>(lasttime[t]+k));
    }
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> lasttime;
        unordered_map<char,int> freq;
        priority_queue<pair<int,char>> pq;
        for(auto i : tasks){
            freq[i]++;
        }
        for(auto &[ch,f] : freq){
            pq.push({f,ch});
        }
        int i=0;
        queue<pair<int,char>> temp;
        while(!pq.empty()){
            while(!pq.empty() && !(lasttime.find(pq.top().second)==lasttime.end() || (cando(lasttime,i,pq.top().second,n) && freq[pq.top().second]>0))){
                    auto str=pq.top();
                    pq.pop();
                    temp.push(str);
                }
            if(!pq.empty() && (lasttime.find(pq.top().second)==lasttime.end() || (cando(lasttime,i,pq.top().second,n) && freq[pq.top().second]>0))){
            auto p=pq.top();
            pq.pop();
            lasttime[p.second]=i;
            if(--freq[p.second]) pq.push({freq[p.second],p.second});
            }
            i++;
            while(!temp.empty()) {
                auto str=temp.front();
                temp.pop();
                pq.push(str);
            }
        }
        return i;
    }
};