//https://leetcode.com/problems/rotate-image/description/

you wrote the input & output, observed their indecies & noticed the pattern among them, you did that in a great way. But just got little confused in the implentation

#include<iostream>
#include<vector>

using namespace std;

  void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                ans[j][n-1-i]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                matrix[i][j]=ans[i][j];
            }
        }
    }

void betterRotate(vector<vector<int>>& matrix) {
    // transpose the matrix & reverse the each row of the matrix.
        for(int i=0;i<n;i++){
            for(int j =i;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i=0;i<n;i++){
          //  reverse(matrix[i].begin(),matrix[i].end());
          int start = 0;
          int end = n-1;
          while(start<end){
                int temp = matrix[i][start];
                 matrix[i][start]= matrix[i][end];
                matrix[i][end] = temp;
                start ++;
                end --;
          }
        }
}

int main(){
  
  return 0;
}
