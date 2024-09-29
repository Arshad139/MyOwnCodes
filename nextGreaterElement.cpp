//https://www.geeksforgeeks.org/next-greater-element/
 //start from the last element of the array
        // push it into the stack, now begin iterating with the penultimate
        // element, check if the top element in the stack is its next greater
        // element, if not, keep popping until the stack is empty, you are 
        // essentially, searching if there is any greater element next to 
        // it in the array sequence, when you popped out everything and found 
        // no greater element, it will imply that there is no next greater
        // element. 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
       
        
        stack<long long> stack;
        vector<long long> ans(n);
        
        for(int i = n-1; i >= 0; i-- ){
            while(!stack.empty() && stack.top() <= arr[i]){
                    stack.pop();
                }
            if(stack.empty()) ans[i] = -1;
            else ans[i] = stack.top();
            stack.push(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
