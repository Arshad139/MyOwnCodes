//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std

int findMaxSum(vector<int>& nums, int k){
  int n = nums.size();
  unordered_set<int> set;
  int left = 0, curr_sum = 0, max_sum = 0;
// You are gonna iterate for the whole array at once.
for(int  right= 0; right < n; right++){
    // this is to ensure that the current element under consideration does not already exists in the window,if yes, you need to trim the window till a point
    // where the element with the same value does not exist anymore in the window, in other words, the window shall now start from the element next to this duplicate element.
    // both the things need to be done - remove the left elements from the set & subtracting their value from the curr_sum 
     while(set.contains(nums[right])){
        set.erase(nums[left]);
        curr_sum = curr_sum - nums[left];
        left++;
    }
  // Because of the first step, you can now add the current (right) element without any extra checks.
  set.insert(nums[right]);
  curr_sum = curr_sum+ nums[right];
  

  //Now if your current window is of the expected size, then only check for the max sum & after that remove the left most element, because we need a window of k size
  if(right - left + 1 == k) {
    max_sum = max(max_sum,curr_sum);
    set.erase(nums[left]);
    curr_sum = curr_sum - nums[left];
    left++;
  }

  return max_sum;
}

int main(){
  vector<int> nums = {1,5,4,2,9,9,9};
  int k =3;
  findMaxSum(nums,k);
  return 0;
}
