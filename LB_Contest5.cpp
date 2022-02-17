
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>

using namespace std;
void reverseTheGroups(vector<int> a, int n, int k) {
    // Write your code here.
    for(int i=0;i<n;i++){
        a[i]=s.top();s.pop();
   
    int st=n-k,e=n-1,ind_s,ind_e;
    while(st>=0){
        ind_s=st;ind_e=e;
        while(ind_s<=ind_e){
            int temp=a[ind_e];
            a[ind_e]=a[ind_s];
            a[ind_s]=temp;
            ind_s++;ind_e--;
        }
        
        e=st-1;
        st=st-k;
    }
 
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    	cout<<endl;
}

int main()
{
    cout<<"Welcome to Online IDE!! Happy Coding :)";
    vector<int> a={2,2,6,8};
    int n=a.size();
    int k=4;
    reverseTheGroups(a,n,k);
    //for(int i=0;i<n;i++) cout<<a[i]<<" ";
    //	cout<<endl;
    return 0;
}
