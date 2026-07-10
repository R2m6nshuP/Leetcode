class Solution {
public:
    int fun(int n,unordered_map<int,int> &m){
        if(n<2) return n;
        if(n==2) return 1;
        if(m[n-1]==0) m[n-1]=fun(n-1,m);
        if(m[n-2]==0) m[n-2]=fun(n-2,m);
        if(m[n-3]==0) m[n-3]=fun(n-3,m);
        return m[n-1]+m[n-2]+m[n-3];
    }
    int tribonacci(int n) {
        unordered_map<int,int> m;
        m[0]=0;
        m[1]=1;
        m[2]=1;
        return fun(n,m);
    }
};