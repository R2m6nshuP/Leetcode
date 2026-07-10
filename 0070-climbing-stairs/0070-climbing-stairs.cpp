class Solution {
public:
    int fun(int n,unordered_map<int,int> &m){
        if(n<=2) return n;
        if(m[n-1]==0) m[n-1]=fun(n-1,m);
        if(m[n-2]==0) m[n-2]=fun(n-2,m);
        return m[n-1]+m[n-2];
    }
    int climbStairs(int n) {
    unordered_map<int,int> m;
    m[1]=1;
    m[2]=2;
    return fun(n,m);
    }
};