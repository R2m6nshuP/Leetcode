class Solution {
public:
    int maximumGap(string skill, string station) {
        int i=0;
        vector<int> inc,dec(skill.size(),0);
        for(int j=0;j<station.size();j++){
            if(i==skill.size()) break;
            if(station[j]==skill[i]){
            inc.push_back(j);
            i++;
            }           
        }
        i=skill.size()-1;
        for(int j=station.size()-1;j>=0;j--){
            if(i<0) break;
            if(station[j]==skill[i]){
            dec[i]=j;
            i--;
            }           
        }
        int ans=0;
        i=0;
        for(i;i<skill.size()-1;i++){
            ans=max(dec[i+1]-inc[i],ans);
            
        }
        return ans;
    }
};