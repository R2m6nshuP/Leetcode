class Solution {
public:
    string multi(int m,string &s){
        string ans="";
        while(m--){
            ans+=s;
        }
        return ans;
    }
    string decodeString(string s) {
        stack<int> sti;
        stack<string> ststr;
        int j=0;
        int num=0;
        while(j<s.size()){
            if(s[j]-'0'>=0 && s[j]-'0'<=9){
                num=10*num+s[j]-'0';
            }
            else{
                if(s[j]=='['){
                sti.push(num);
                num=0;
                ststr.push("[");
                }
                else if(s[j]==']'){
                    string temp="";
                    while(!ststr.empty() && ststr.top()!="["){
                        temp=ststr.top()+temp;
                        ststr.pop();
                    }
                    ststr.pop();
                    ststr.push(multi(sti.top(),temp));
                    sti.pop();
                }
                else ststr.push(string(1,s[j]));
            }
            j++;
        }
        string ans="";
        while(!ststr.empty()){
            ans=ststr.top()+ans;
            ststr.pop();
        }
        return ans;
    }
};