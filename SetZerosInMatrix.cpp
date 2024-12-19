https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // create 2 maps row_map , column_map, store the indexes of 0 valued
        // elements in these two maps. In the second traversal, if you come
        // across an element whose index matches with  that of the ones
        // in the map, then just make them zero.
        int m = matrix.size();
        int n = (m > 0) ? matrix[0].size() : 0;
//Initial Approach with some space complexity
        unordered_set<int> rows;
        unordered_set<int> columns;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows.count(i) || columns.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
// THe below thing can be done to overcome the space complexity
        bool ZeroInFirstRow = false;
        bool ZeroInFirstColumn = false;
        // check if the first row or first column has a zero
        for (int j=0;j<n;j++){
            if(matrix[0][j] ==0) ZeroInFirstRow = true;
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0] ==0) ZeroInFirstColumn = true;
        }


        // Iterate over the rest of the matrix except the first row & first column & if a zero is found , mark the corresponding elements in the first row & the first column. 

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == 0){
                     matrix[0][j]=0;
                    matrix[i][0]=0;
                }
                   
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(ZeroInFirstRow){
            for(int j=0;j<n;j++) matrix[0][j]= 0;
        }
         if(ZeroInFirstColumn){
            for(int i=0;i<m;i++) matrix[i][0]= 0;
        }
    }


};
