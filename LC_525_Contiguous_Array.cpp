//https://leetcode.com/problems/contiguous-array/description/
int findMaxLength(vector<int>& nums) {
        // int zeroCount = 0;
        // int OneCount = 0;
        // int n = nums.size();
        // int left = 0;
        // int curr_len = 1;
        // int max_len = 0;

        // if(nums[0] == 0) zeroCount++;
        // else OneCount++;
        // for(int i = 1;i<n; i++){
        //     if(nums[i] == 0) zeroCount++;
        //     else OneCount++;
            
        //     curr_len++;

        //     if(zeroCount == OneCount) max_len = max(max_len, curr_len);

        //     cout<<"nums[i]= "<<nums[i]<<" i= "<<i<<" curr_len= "<<curr_len<<" max_len= "<<max_len<<"\n";

        //     // if(zeroCount - OneCount == 1 && nums[left] == 0){
        //     //     left++;
        //     //     curr_len--;
        //     // }

        //     //  if(OneCount - zeroCount == 1 && nums[left] == 1){
        //     //     left++;
        //     //     curr_len--;
        //     // }
        // }
        // return max_len;

      // Above was your initial approach, that really did not work, you thought of using sliding window, but you really caannot identify when you need to trim down 
  // your window because of violation of the criteria, what you needed is a prefix information. see you soon.

        unordered_map<int,int> hash;
        int n = nums.size(), zeroCount = 0, oneCount = 0, max_length=0;

        for(int i = 0; i<n; i++){
            if (nums[i]) oneCount++;
            else zeroCount++;

            if(!hash.contains(oneCount - zeroCount)) hash[oneCount - zeroCount] = i;

            if(oneCount == zeroCount) max_length = oneCount + zeroCount;

            else max_length = max(max_length, i-hash[oneCount - zeroCount]);
            cout<<"oneCount= "<<oneCount<<" zeroCount= "<<zeroCount<<"\n";
        }

        return max_length;
    }
