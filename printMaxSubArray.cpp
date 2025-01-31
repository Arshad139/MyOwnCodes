//https://www.geeksforgeeks.org/print-the-maximum-subarray-sum/
// you can go on the above link & try it out yourself in the inbuilt editor. 
// Eat it! - Any coding problem. 

vector<int> maxSumSubarray(vector<int> &arr) {
    int n = arr.size();
  	int curr_sum = arr[0];
  	int max_sum = INT_MIN;
  	int window_start = 0;
  	int window_end = 0;
  	
  	for(int i =  1; i < n ; i++){
      	if(curr_sum == 0) window_start = i ;
    	curr_sum = curr_sum + arr[i];
      	max_sum = max(max_sum, curr_sum);
      	if(curr_sum == max_sum) window_end = i;
      	
      	if(curr_sum < 0) curr_sum = 0;
    }
  	
  	vector<int> ans;
  	for(int i = window_start; i<= window_end; i++){
    	ans.push_back(arr[i]);
    }
  	return ans;
}

// If you dont really need to print 
// https://leetcode.com/problems/maximum-subarray/
 int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        int curr_sum = 0;
        for (int i=0;i<n;i++){
            // append the cuurent element to the current sum
            curr_sum = curr_sum + nums[i];
            // evaluate for the maximum between the max value and current sum
            max_sum = max(max_sum,curr_sum);
            // if you come across a negative sum or a negative value, its not gonna help you get
            // to that maximum sum, hence cut that off, by making the current sum as zero.
            // And this (curr sum being 0) can be used in the next iteration, to identiy the start
            // of a subarray and you can hence use the condition to declare the start index, 
            // and when do you identiy the its the end index of the sliding window(subArray)?
            // its when you come across a condition where max sum value gets changed when the curr sum has a 
            // higher value
            if(curr_sum < 0) curr_sum = 0;
        }
        
