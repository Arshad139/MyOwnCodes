// My First Approach
int maximumProfit(vector<int> &p){
    // Write your code here.
    int n=p.size();
    //cout<<"Size is "<<n<<endl;
    if(n==2){
        
        if(p[0]<p[1]) return p[1]-p[0];
        else return 0;
    }
    //find min
    int min=p[0],min_ind=0,prev_min=p[0],prev_min_ind=0;
    for(int i=0;i<n;i++){
        if(p[i]<min) {
            prev_min_ind=min_ind;
            prev_min=min;
            min=p[i];min_ind=i;
        }
    }
    //cout<<min<<"--"<<min_ind<<"--"<<prev_min_ind<<endl;
    if(min_ind==n-1) {
        min_ind=prev_min_ind;
        min=prev_min;
    }
    if(min_ind==n-2) return p[n-1]-p[n-2];
    int max=p[min_ind+1];
    
    for(int i=min_ind+1;i<n;i++) if(p[i]>max) max=p[i];
    //cout<<"max--"<<max<<endl;
    return max-min;
}


// Brute Force Approach
//we assume that the cuurent element in the array is the price to buy and iterate through the rest of the array to find the max profit value to sell and store the max value of this iteration.
//We do the same for the rest of the array elements by comparing with the elements present to the right of that current element and check if its the max so far.
int Stocks(vector<int> &p){
  int n=p.size();
  int max_so_far=0;
  for(int i=0;i<n;i++){
      int curr_max = 0;
      for(int j=i+1;j<n;j++){
        curr_max=max(curr_max,p[j]-p[i]);
      }
      max_so_far=max(curr_max,max_so_far);
  }
  return max_so_far;
}

//Optimised Brute Force
Optimised Brute Force
We will iterate over the array and as we go along we will update the buying price as the minimum of the prices till now and will also update the ‘MaxProfit’ variable if selling at this time is more profitable. 
 

Algorithm:

 

Initialize a variable ‘BUY’ to store the buying price and ‘MaxProfit’ to store the maximum profit we can achieve.
Now we will iterate over the array.
If the current price is less than our buying price, we will update that.
Else if selling at this minute gives us more profit, then we will update our ‘MaxProfit’ variable as ‘Prices[i]’ - ‘BUY’.
Finally, return the ‘MaxProfit’ variable.
Time Complexity
O(N), where ‘N’ is the size of the array.

int Stocks_opt(vector<int> &p){
    int n=p.size();
    int buy=p[0];
    int maxProfit=0;
    for(int i=0;i<n;i++){
        if(p[i]<buy) buy=p[i];
        else if(p[i]-buy>maxProfit) maxProfit=p[i]-buy
    } 
    return maxProfit;
}
