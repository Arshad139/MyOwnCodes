https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// Good Example of sliding window algorithm, it was needed to find out the maximum possible sum of a sub array of given size. 
// For which you have to calculate the first k elements sum, and do the actual sliding of the window, you need to add the ith element & need to subtract the first element 
// of the window, to find its index was tricky for you, the size of your window is k. so the first element is k elements behind the current ith element. so a[i-k] is the first 
// element of the sliding window

long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
         if (N < K) {
          return -1; // or any other error handling logic
         }
        long max_sum =0, window_sum =0;
        
        for(int i = 0; i < K; i++){
            window_sum = window_sum + Arr[i];
        }
        
        max_sum = window_sum ;
        
        for(int i =K; i<N; i++){
            window_sum = window_sum + Arr[i] - Arr[i-K];
            max_sum = max(max_sum, window_sum);
        }
        
        return max_sum;
    }
