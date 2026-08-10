class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans="";
        for(auto i : s){
            if(i-'0'<=9 && i-'0'>=0){
                ans.pop_back();
                st.pop();
            }
            else{
                ans.push_back(i);
                st.push(i);
            }
        }
        return ans;
    }
};