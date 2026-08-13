class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l=1;
        int r=area;
        int ans=-1;
        for(int l=1;l*l<=area;l++){
            if(area%l==0){
                ans=l;
            }
        }
        vector<int> temp;
        temp.push_back(area/ans);
        temp.push_back(ans);
        return temp;
    }
};