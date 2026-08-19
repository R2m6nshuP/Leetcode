class Solution {
public:
    void pse(vector<int>& arr,vector<int>& pe){
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                pe[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
    void nse(vector<int>& arr,vector<int>& ne){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                ne[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pe(arr.size(),-1);
        vector<int> ne(arr.size(),arr.size());
        pse(arr,pe);
        nse(arr,ne);
        long long ans=0;
        int mod =1e9+7;
        for(int i=0;i<arr.size();i++){
            ans=(ans+(arr[i]*(long long)((ne[i]-i)*(i-pe[i]))%mod)%mod)%mod;
        }
        return ans;
    }
};