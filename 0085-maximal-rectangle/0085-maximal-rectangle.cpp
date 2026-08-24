class Solution {
public:
    int helper(vector<int> his){
        stack<int> st;
        vector<int> range(his.size(),his.size());
        for(int i=0;i<his.size();i++){
            while(!st.empty() && his[i]<his[st.top()]){
                range[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=his.size()-1;i>=0;i--){
            while(!st.empty() && his[i]<his[st.top()]){
                range[st.top()]-=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            range[st.top()]++;
            st.pop();
        }
        int ans=0;
        for(int i=0;i<his.size();i++){
            ans=max(ans,(range[i]-1)*his[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> his(matrix[0].size(),0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]-'0'){
                    his[j]+=matrix[i][j]-'0';
                }
                else{
                    his[j]=0;
                }
            }
            ans=max(ans,helper(his));
        }
        return ans;
        }
};