class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        vector<int> ele(heights.size(),heights.size());
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                ele[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                ele[st.top()]-=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            ele[st.top()]-=-1;
            st.pop();
        }
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(ele[i]-1));
        }
        return ans;
    }
};