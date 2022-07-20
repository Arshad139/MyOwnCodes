int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        //First approach which is the brute force
     /*   for(int i=0;i<n;i++){
            int left=0,right=0;
            
            for(int j=0;j<i;j++){
                left=left+nums[j];
            }
            
            for(int k=i+1;k<n;k++){
                right=right+nums[k];
            }
            
            if(left==right) return i;
        }
         return -1;*/
  // We used another array that stores the left sums of all the indexes and then we calculate the right sum using this array and total sum value
        int sum=0,rightsum=0;
        vector<int> hash(n);
        hash[0]=0;
        
        for(int i=0;i<n;i++){
            sum=sum+nums[i];            
        }
        
        for(int i=1;i<n;i++){
            hash[i]=hash[i-1]+nums[i-1];            
        }
        
        for(int i=0;i<n;i++){
            rightsum=sum-hash[i]-nums[i];    
            if(rightsum==hash[i]) return i;
        }
        
        return -1;
    }
//But this has been the best approach I believe because the right sum and left sum, both are being calculated dynamically
int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        for(int i=0;i<nums.size();i++){            
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
