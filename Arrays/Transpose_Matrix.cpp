/*
Category: Matrix
Approach:
Create a new matrix with swapped dimensions and place each element
matrix[j][i] into position transpose[i][j], effectively converting rows into columns.
Time Complexity: O(n * m)
Space Complexity: O(n * m)
Where n and m are dimensions of the matrix
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
        vector<vector<int>> t(m,vector<int>(n));
        for(int i = 0 ;i<m ; i++){
            for(int j = 0 ; j< n ;j++){
                t[i][j] = matrix[j][i];
            }
        }
        return t;
    }
};