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
    vector<vector<int>> generate(int numRows) {
        int m = numRows;
    vector< vector<int> > v;
    for(int i =1; i<=m ; i++){
        vector<int>a(i);
        v.push_back(a);
    }
    //generate

for(int i=0 ; i<m ; i++){
    for(int j=0 ; j<=i; j++){
        if(j==0 || j==i)
            v[i][j] = 1;
        
        else
            v[i][j] = v[i-1][j] + v[i-1][j-1];
        
    }
}
return v;
    }
};