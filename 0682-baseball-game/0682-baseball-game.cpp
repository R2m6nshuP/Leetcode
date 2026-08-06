class Solution {
public:
    int str(string s){
        int ans=0;
        int i=0;
        int sign=1;
        if(s[0]=='-'){
            i=1;
            sign=-1;
        } 
        for(i;i<s.size();i++){
            ans=10*ans+s[i]-'0';
        }
        return ans*sign;
    }
    int calPoints(vector<string>& operations) {
        int sum=0;
        stack<int> st;
        int prev=-1;
        int curr=-1;
        int val;
        for(auto i : operations){
            if(i=="+"){
                curr=st.top();
                st.pop();
                prev=st.top();
                st.push(curr);
                val=prev+curr;
                st.push(val);
 
            }
            else if(i=="D"){
                val=st.top()*2;
                st.push(val);
 
            }
            else if(i=="C"){
                st.pop();
            }
            else{
                val=str(i);
                st.push(val);
 
            }
        }
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};