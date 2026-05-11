/*
Category: Matrix / Greedy
Approach:
First make sure every row starts with 1 by flipping rows when needed,
since the leftmost bit contributes maximum value.
Then for each column, flip it if zeros are more than ones to maximize binary contribution.
Finally compute decimal value of each binary row and sum them.
Time Complexity: O(m * n)
Space Complexity: O(1)
Where operations are performed directly on the given matrix
*/
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for(int i=0; i<m; i++){
        if(grid[i][0]==0){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) grid[i][j] = 1;
                else grid[i][j]=0;
            }
        }
    }  
   
    for(int j=0 ; j<n ; j++){
         int noz = 0;
        int noo = 0;
        for(int i=0 ;i<m;i++){
            if(grid[i][j]==0) noz++;
            else noo++;
        }
        if(noz>noo){
            for(int i=0 ;i<m;i++){
                if(grid[i][j] == 0) grid[i][j]=1;
                else grid[i][j] =0;
            }
        }
    } 
    int sum=0;
    for(int i=0;i<m;i++){
        int x=1;
        for(int j=n-1 ; j>=0; j--){
            sum+=grid[i][j]*x;
            x*=2;

        }
    }
    return sum;
    }
};