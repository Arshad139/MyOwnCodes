#include<unordered_map>
class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int len=nums.size();
      
        for(auto i=0;i<len;i++) {
            int diff=target-nums[i];
            if(hash.count(diff)) 
                 return {i,hash[target-nums[i]]};
            else 
               hash[nums[i]]=i;
        
        }
         return {-1};      
        }
                                   
};
