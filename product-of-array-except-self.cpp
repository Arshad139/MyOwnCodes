//https://leetcode.com/problems/product-of-array-except-self/description/

// Below is the initial approach, with 2 extra vectors or arrays. 

 vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> ans(n);
        prefix[0] = 1;
        suffix[n-1] = 1;

        for(int i = 1; i<n; i++) prefix[i] = prefix[i-1]*nums[i-1];
        for(int i = n-2; i>=0; i--) suffix[i] = suffix[i+1]*nums[i+1];

        for(int i =0; i<n ; i++) ans[i] = prefix[i] * suffix[i];
        
        return ans;
    }

// This can be improved by just using the prefix array itself & to find the value of the prefix product for a given element, just use a variable suffix, 
// that will trach the suffix product, and now you have to traverse backwards, by this approach you can take advantage



 vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1);
        int suffix = 1;
   
        for(int i = 1; i<n; i++) prefix[i] = prefix[i-1]*nums[i-1];

        for(int i=n-1; i>=0; i--) {
            prefix[i] = prefix[i] * suffix;
            suffix = suffix * nums[i];
        }
        return prefix;
    }
