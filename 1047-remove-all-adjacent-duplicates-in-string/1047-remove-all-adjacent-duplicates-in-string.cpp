class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans="";
        for(auto i : s){
            if(!st.empty() && i==st.top()){
                st.pop();
                ans.pop_back();
            }
            else {
                st.push(i);
                ans.push_back(i);
            }
        }
        return ans;
    }
};