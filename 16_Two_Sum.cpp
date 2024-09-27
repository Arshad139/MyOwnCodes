#include<unordered_map>
class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int len=nums.size();
      
        for(auto i=0;i<len;i++) {
            int diff=target-nums[i];
            if(hash.count(diff)) 
                 return {i,hash[diff]};
            else 
               hash[nums[i]]=i;
        
        }
         return {-1};      
        }

// The below is one of the straight forward approaches. has a worst case complexity of O(n2), iterate over the array by 
//assuming that the current element is one of the required ones & check if any of the other elements in the array, combined
// with the current element, if the condition is met, then return the indices by breaking the loop.
vector<int> initialTwoSum(vector<int>& nums, int target) {
        int i=0,j=0;
        int len = nums.size();
        vector<int> ans(2, 0); 
        for (i = 0; i < len; i++){
            for(j= i+1 ; j< len; j++){
                if(nums[i] + nums[j] == target){
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
                    
            }
        }
        return ans;
        
    }
                                   
};
