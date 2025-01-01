//https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;

        // for(int i =m; i<n+m;i++){
        //     nums1.erase(nums1.begin()+i);
        // }

        // if(m==0){
        //     for(int i =0;i<n;i++){
        //         nums1.push_back(nums2[i]);
        //     }
        //     return;
        // }

        // int i = 0, j =0;
        // while(j<n && i<m){
        //     if(nums2[j] >= nums1[i] & nums2[j] <=nums1[i+1]){
        //         nums1.insert(nums1.begin() + i + 1, nums2[j]);
        //         j++; m++;
        //     }
        //     i++;
        // }
        // while(j<n) nums1.push_back(nums2[j++]);

        // Mergeing the 2 sorted list from the ending, will minimize the movements that you had observed that
        // were happening in the first approach & the extra elements added in the first array will be better 
        // utlized this way. 

        //Declare 2 pointers left & right

        int left = m-1;
        int right = n-1;
        int index = m+n-1;

        while(left>=0 & right >=0){
            if(nums2[right] >= nums1[left]) nums1[index--] = nums2[right--];
            else nums1[index--] = nums1[left--];
        }

       while (right >= 0) nums1[index--] = nums2[right--];

    }
};
