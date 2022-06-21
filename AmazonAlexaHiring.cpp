#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;
bool validate (string S, vector<vector<int> > &ranges,int &Q){
  unordered_set<char> set1;
  int dup=0;
  //int l=Q;
  for(int r=0;r<Q;){
      
            int lb=ranges[r][0]-1;
            int ub=ranges[r][1]-1;
           
           for(int i=lb;i<=ub;i++){
            if(S[i]!=' '){
                if(set1.find(S[i])!=set1.end()){
                    dup=1;
                    break;
            }
             else set1.insert(S[i]);
            }
      }
      set1.clear();
      if(dup==1) return false;
      if(dup==0) {
          
          ranges.erase(ranges.begin()+r);
            Q--;
        }
      
           
  }
  return true;
}

int goodString (int N, int Q, string S, vector<int> arr, vector<vector<int> > ranges) {
   // Write your code here
   int ans=0;

   while(ans<N){
       if(validate(S,ranges,Q)) break;
       else{
           
           S[arr[ans]-1]=' ';
           ans++;
       }
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int Q;
        cin >> Q;
        string S;
        cin >> S;
        vector<int> arr(N);
        for(int i_arr = 0; i_arr < N; i_arr++)
        {
        	cin >> arr[i_arr];
        }
        vector<vector<int> > ranges(Q, vector<int>(2));
        for (int i_ranges = 0; i_ranges < Q; i_ranges++)
        {
        	for(int j_ranges = 0; j_ranges < 2; j_ranges++)
        	{
        		cin >> ranges[i_ranges][j_ranges];
        	}
        }

        int out_;
        out_ = goodString(N, Q, S, arr, ranges);
        cout << out_;
        cout << "\n";
    }
}
