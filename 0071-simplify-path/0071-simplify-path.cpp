class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        int j=1;
        stack<string> st;
        while(j<path.size()){
            if(path[j]=='/') {
                string s=path.substr(i,j-i);
                if(s=="/") ; 
                else if(s=="/.") ;
                else if(s=="/..") {
                    if(!st.empty()) st.pop();
                }
                else st.push(s);
                i=j;
                j=i+1;

            }
            else{
                j++;
            }
        }
        if(i<path.size()-1 && j==path.size()){
                string s=path.substr(i,j-i);
                if(s=="/") ; 
                else if(s=="/.") ;
                else if(s=="/..") {
                    if(!st.empty()) st.pop();
                }
                else st.push(s);
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        if(ans=="") return "/";
        return ans;
    }
};