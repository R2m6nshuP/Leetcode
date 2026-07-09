class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copy(m);
        for(int i=0;i<m;i++) copy[i]=nums1[i];
        nums1.resize(m+n);
        int l=0;
        int r=0;
        int i=0;
        while(l<m && r<n){
            if(copy[l]<nums2[r]){
                nums1[i]=copy[l];
                l++;
                i++;
            }
            else{
                nums1[i]=nums2[r];
                i++;
                r++;
            }
        }
        while(l<m){
                nums1[i]=copy[l];
                l++;
                i++;
        }
        while(r<n){
                nums1[i]=nums2[r];
                i++;
                r++;
            }

    }
};