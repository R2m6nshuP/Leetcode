class Solution {
public:
    string reverseWords(string s) {
        int t=0;
        string ans="";
    int start=-1;
    int end;
        for(t;t<s.size();t++){
            if(s[t]==' ' && start==-1) continue;
            else if(s[t]==' ' && start!=-1) {
                end=t;
                string add=s.substr(start,end-start);
                start=-1;
                reverse(add.begin(),add.end());
                if(ans!="") ans+=" ";
                ans+=add;
                

            }
            else if(s[t]!=' ' && start==-1){
                start=t;
            }
        }
        if(start!=-1) {
                string add=s.substr(start,s.size()-start);
                reverse(add.begin(),add.end());
                if(ans!="") ans+=" ";
                ans+=add;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};