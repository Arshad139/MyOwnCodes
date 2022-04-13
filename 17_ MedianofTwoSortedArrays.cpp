class Solution {
public:
  // First First approach by me 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //1. merge both arrays 
        int len1=nums1.size();
        int len2=nums2.size();
        int n=len1+len2;
        vector<int> merged(n);
        
        int ind1=0,ind2=0,indm=0;
        while(ind1<len1 && ind2<len2){
            if(nums1[ind1]<nums2[ind2])
                merged[indm++]=nums1[ind1++];
            else merged[indm++]=nums2[ind2++];
        }
        
        while(ind1<len1){
            merged[indm++]=nums1[ind1++];
        }
        
        while(ind2<len2){
            merged[indm++]=nums2[ind2++];
        }
        
        if(n%2==1){
            return merged[n/2];
            
        }
        else {
            double ans= (merged[n/2]+merged[(n/2)-1])/2.0;
            return ans;
        }
        //
    }
};
