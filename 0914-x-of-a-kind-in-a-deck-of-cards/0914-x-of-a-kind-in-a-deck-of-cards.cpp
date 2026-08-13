class Solution {
public:
    int gcd(int n,int m){
        if(n==1 || m==1) return 1;
        if(m>n) swap(n,m);
        if(n%m==0) return m;
        return gcd(n%m,m);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()==1) return 0;
        unordered_map<int,int> mp;
        for(auto i : deck){
            mp[i]++;
        }
        int x=-1;
        for(auto &[i,v] : mp){
            if(x<0) x=v;
            else{
                x=gcd(x,v);
            }
        }
        return x!=1;
    }
};