class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto i : s){
            if(st.empty() || abs(int(i)-int(st.top()))!=abs('A'-'a')) st.push(i);
            else st.pop();
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};