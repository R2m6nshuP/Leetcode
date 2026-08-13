class Solution {
public:
    bool selfDividing(int n){ 
        if(n==0) return 1;
        int copy=n;
        while(n){
            if(n%10==0) return 0;
            if(copy%(n%10)==0){
                n/=10;
            }
            else return 0;
        }
        return 1;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(left;left<=right;left++){
            if(selfDividing(left)) ans.push_back(left);
        }
        return ans;
    }
};