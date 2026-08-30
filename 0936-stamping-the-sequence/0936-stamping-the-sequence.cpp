class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int dot=0;
        int pos=0;
        vector<int> ans,temp;
        int t=0;
        auto z=target.find(stamp);
        if(z==string::npos) return temp;
        pos=z;
        while(dot<target.size() && t<target.size()){
            bool ok=1;
            int diff=0;
            for(int i=0;i<stamp.size();i++){
                if(pos+i>=target.size()) {
                    ok=0;
                    break;
                }
                if(target[pos+i]!=stamp[i] && target[pos+i]!='*') {
                    ok=0;
                    break;
                }
                if(target[pos+i]!='*') diff++;
            }
            if(ok && diff>0){
                ans.push_back(pos);
               for(int i=0;i<stamp.size();i++){
                if(pos+i>=target.size()) break;
                if(target[pos+i]!='*') dot++;
                target[pos+i]='*';
                    } 
            }
            if(pos+1==target.size()) t++;
            pos=(pos+1)%target.size();
            
        }
        reverse(ans.begin(),ans.end());
        return dot==target.size() ? ans : temp;
    }
};