/*
Category: Matrix (Primary)

Approach:
First transpose the matrix (swap i,j with j,i),
then reverse each row to achieve 90-degree clockwise rotation.

Time Complexity: O(n^2)
Space Complexity: O(1)

Where n = dimension of the matrix.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i<j) swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(int i = 0 ; i<n ; i++){
            int l = 0 , r = n-1;
            while(l<r){
                swap(matrix[i][l],matrix[i][r]);
                l++;
                r--;
            }
        }
    }
};