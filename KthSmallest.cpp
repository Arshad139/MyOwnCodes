//This runs for a long time, sometimes fails for long sequences

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
   int kthSmallest_Stl(int arr[], int n, int k)// Uses STL to sort the array and then we use the nth index O(NLogN)
   {
       // Sort the given array
      sort(arr,arr+n);
      return[k-1]; 
   }
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) { // This uses Bubble sort k times to find the kth largest/smallest . TC is O(nk)
        for(int i=0;i<k;i++){
            for(int j=0;j<r-i;j++){
                if (arr[j]<arr[j+1]){
                    //swap
                    int t=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=t;
                }
            }
            
        }
        return arr[r-k+1];
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
