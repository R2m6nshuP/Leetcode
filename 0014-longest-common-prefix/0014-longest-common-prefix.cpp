class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        
        int i=0;
        string ans="";
        int len=min(strs[0].length(),strs[strs.size()-1].length());
        while(i<len){
            if(strs[0][i]==strs[strs.size()-1][i]){
                ans+=strs[0][i];
                i++;
            }
            else {
                break;
            }
            
        }
        // ans+=strs[strs.size()-1].substr(0,i);
        return ans;
    }
};