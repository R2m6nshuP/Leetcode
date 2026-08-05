class Solution {
public:
    int helper(unordered_set<int> &s,int n){
        if(n==1) return n;
        if(s.count(n)) return n;
        s.insert(n);
        int m=0;
        while(n){
            m+=(n%10)*(n%10);
            n/=10;
        }
        return helper(s,m);
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        if(n==1) return 1;
        return helper(s,n)==1;
    }
};