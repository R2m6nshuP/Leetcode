class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        vector<int> h(height.size());
        int m=0;
        for(int i=0;i<height.size();i++){
            if(height[i]>=m) m=height[i];
            h[i]=m;
        }
        m=0;
        for(int i=height.size()-1;i>=0;i--){
            if(height[i]>=m) m=height[i];
            h[i]=min(m,h[i]);
        }
        for(int i=height.size()-1;i>=0;i--){
            if(h[i]==0) continue;
            else{
                if(h[i]-height[i]>0) ans+=h[i]-height[i];
            }
        }
        return ans;
    }
};