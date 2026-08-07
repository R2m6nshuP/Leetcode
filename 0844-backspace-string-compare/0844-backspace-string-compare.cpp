class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st,st2;
        for(auto i : s){
            if(i!='#') st.push(i);
            else if( !st.empty() && i=='#') st.pop();
        }
        for(auto i : t){
            if(i!='#') st2.push(i);
            else if( !st2.empty() && i=='#') st2.pop();
        }
        while(!st.empty() && !st2.empty()){
            if(st.top()!=st2.top()) return 0;
            st.pop();
            st2.pop();
        }
        if(st.empty() && st2.empty()) return 1;
        else return 0;

    }
};