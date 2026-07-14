class Solution {
public:
    // int beauty(string s){
    //     if(s.size()==1) return 0;
    //     unordered_map<char,int> mp;
    //     for( auto i: s){
    //         mp[i]++;
    //     }
    //     int maxi=INT_MIN;
    //     int mini=INT_MAX;
    //     for( auto &[ch,fq]: mp){
    //         maxi=max(maxi,fq);
    //         mini=min(mini,fq);
    //     }
    //     return maxi-mini;
    // }
    // int beautySum(string s) {
    //     if(s.size()==1) return 0;
    //     int ans=0;
    //     for(int j=1;j<s.size();j++){
    //         ans+=beauty(s.substr(0,j+1));
    //     }
    //     return ans+beautySum(s.substr(1));
    //O(n3)
    int beautySum(string s) {
    int ans=0;
    for(int i=0;i<s.size();i++){
        vector<int> fq(26,0);
        for(int j=i;j<s.size();j++){
            fq[s[j]-'a']++;
            if(j==i) continue;
            int mini=s.size();
            int maxi=0;
            for(auto f : fq){
                if(f){
                maxi=max(maxi,f);
                mini=min(mini,f);
                }
            }
            ans+=maxi-mini;
        }
    }
    return ans;
    }
};