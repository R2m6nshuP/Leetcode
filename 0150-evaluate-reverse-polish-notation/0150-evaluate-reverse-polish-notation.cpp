class Solution {
public:
    int convert(string s){
        int ans=0;
        int sign=1;
        for(auto i : s){
            if(ans==0 && i=='-') {
                sign=-1;
                continue;
            }
            ans=10*ans+i-'0';
        }
        return ans*sign;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto i : tokens){
            if(i=="*" || i=="+" || i=="/" ||i=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int z;
                if(i=="+") z=(a+b);
                if(i=="*") z=(a*b);
                if(i=="-") z=(b-a);
                if(i=="/") z=(b/a);
                st.push(z);
            }
            else{
                st.push(convert(i));
            }
        }
        return st.top();
    }
};