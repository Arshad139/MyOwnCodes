//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        // Find the breaking point, has a peak, when reading from the end
        int breakingPoint = -1;
        for(int i = n-2;i>=0;i--){
            // Starting from the penultimate number to check if it less than its element on its right 
            if(nums[i] < nums[i+1]){
                breakingPoint = i;
                break;
            }
        }

        if(breakingPoint == -1){
            // no peak found, its a linear line, meaning, its the highest ordered sequence
            reverse(nums.begin(),nums.end());
            return;
        }

        // Find the element from the right part which is greater than the number at the breaking point, find 
        //the smallest among them, start from the right end, because it is in an increasing order from there.
        for(int i = n-1;i>breakingPoint;i--){
            if(nums[i]>nums[breakingPoint]){
                swap(nums[i],nums[breakingPoint]);
                break;
            }
        }

        //Now, with all the elements in the right side of the breaking Point index, you need to get the 
        //smallest possible number combining those digits, this part of the array is a decreasing curve
        //as we observed, we can now just reverse it & we will have the next greateer permutation of the 
        //given sequence.

        reverse(nums.begin()+breakingPoint+1,nums.end());

        return;
    }
};
