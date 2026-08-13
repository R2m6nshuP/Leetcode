class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int fmax=INT_MIN,smax=INT_MIN,tmax=INT_MIN,fmin=INT_MAX,smin=INT_MAX;
        for(auto i: nums){
            if(i>fmax){
                tmax=smax;
                smax=fmax;
                fmax=i;
            }
            else if(i>smax){
                tmax=smax;
                smax=i;
            }
            else if(i>tmax){
                tmax=i;
            }
            if(i<fmin){
                smin=fmin;
                fmin=i;
            }
            else if(i<smin){
                smin=i;
            }
        }
        long long int pos,neg;
        pos=fmax*smax*tmax;
        neg=fmin*smin*fmax;
        return max(pos,neg);
    }
};