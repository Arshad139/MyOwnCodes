https://leetcode.com/problems/find-the-duplicate-number/

#include<iostream>
#include<vector>

this could have been done by simply sorting an array
or using a hash set to keep pushing & checking the existance of the element in that set
but below tortoise method helps much better.

using namespace std;
    int findDuplicate(vector<int>& nums) {
      
        // int n = nums.size();
        // int ans = -1;
        // int xor_so_far = nums[0];
        // for(int i = 1; i<n; i++){
        //     xor_so_far = xor_so_far ^ nums[i];
        //     if (xor_so_far == 0 ) {ans = nums[i]; break;}
        // }
        // return ans;
        int fast = nums[0];
        int slow = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);

        fast = nums[0];
        while(slow!=fast)  {
            slow = nums[slow];
            fast = nums[fast];
        }      

        return slow;
    }

int main(){
  vector<int> nums = {2,4,5,6,7,8,8};
  cout<<findDuplicate(nums);
  return 0;
}
