class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="") return 0;
        vector<bool> v(s.size(),0);
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='(') {
                    v[st.top()]=1;
                    v[i]=1;
                    st.pop();
                }
                else st.push(i);
            }
        }
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(v[i]) cnt++;
            else{
                ans=max(cnt,ans);
                cnt=0;
            }
        }
        ans=max(cnt,ans);
        return ans;
    }
};