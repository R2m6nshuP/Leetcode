class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());

    int sIndex = 0; 
    int gIndex = 0;  

        while (sIndex < s.size() && gIndex < g.size()) {
            if (g[gIndex] <= s[sIndex]) {
                gIndex++; 
            }
            sIndex++; 
        }
        return gIndex;   
    }
};