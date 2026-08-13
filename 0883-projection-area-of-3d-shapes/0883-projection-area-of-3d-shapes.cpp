class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int maxi=-1;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[i][j]);
                if(grid[i][j]>0) sum++;
            }
            sum+=maxi;
        }
        for(int i=0;i<n;i++){
            int maxi=-1;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[j][i]);
            }
            sum+=maxi;
        }
        return sum;
    }
};