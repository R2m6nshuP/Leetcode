class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int maxl1=INT_MIN,maxl2=INT_MIN,minr1=INT_MAX,minr2=INT_MAX;
        int part1,part2;
        int l=0;
        int r=nums1.size();
        
        while(l<=r){
            part1=(l+r)/2;
            part2=(nums1.size()+nums2.size()+1)/2-part1;

            maxl1= part1==0 ? INT_MIN : nums1[part1-1];
            maxl2= part2==0 ? INT_MIN : nums2[part2-1];
            minr1= part1==nums1.size() ? INT_MAX: nums1[part1];
            minr2= part2==nums2.size() ? INT_MAX: nums2[part2];

            if(maxl1<=minr2 && maxl2<=minr1){
                if((nums1.size()+nums2.size())%2==0){
                    return ((float)(max(maxl2,maxl1)+min(minr2,minr1)))/2;
                }
                else return max(maxl2,maxl1);
            }
            else {
                if(maxl1>minr2) r=part1-1;
                else l=part1+1;
            }
        }
        return -1;
    }   
};
