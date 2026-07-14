class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    unordered_map<int,int> mp;
    int i=0;
    for(i;i<bills.size();i++){
        if(bills[i]==5) mp[5]++;
        else if(bills[i]==10){
            if(!mp[5]) return 0;
            else {
                mp[10]++;
                mp[5]--;
            }
        }
        else{
            if((mp[5]>=1 && mp[10]>=1)){
                mp[5]--;
                mp[10]--;
                mp[20]++;
            }
            else if(mp[5]>=3) {
                mp[5]-=3;
                mp[20]++;
            }
            else return 0;
        }

    }
    return 1; 
    }
};