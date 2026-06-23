class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int r=0;
        int cnt=0;
        int start=-1;
        int end;
        while(r<s.size()){
            if(s[r]=='('){
                cnt++;
                if(cnt==2 && start==-1){
                    start=r;
                }
            }
            else if(s[r]==')'){
                cnt--;
                if(cnt==0 && start>0){
                    end=r;
                    ans+=s.substr(start,end-start);
                    start=-1;
                }
            }
            r++;
        }
        return ans;
    }
};