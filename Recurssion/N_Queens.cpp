/*
Category: Backtracking
Approach:
Place queens column by column and try every row for the current column. Use three arrays
(leftRow, lowerDiagonal, upperDiagonal) to efficiently check if placing a queen is safe in O(1).
If safe, place the queen, mark the constraints, recurse for next column, and backtrack by unmarking.
Once all columns are filled, store the board configuration as a valid solution.
Time Complexity: O(N!)
Space Complexity: O(N)
Where recursion depth is N and auxiliary arrays track constraints
*/
class Solution {
public:
    void solve(int col ,vector<string> &board ,vector<vector<string>> &ans ,vector<int>&leftRow ,vector<int>&lowerDiagonal ,vector<int>&upperDiagonal ,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row < n ; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1 , board , ans ,leftRow, lowerDiagonal ,upperDiagonal , n);
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n);
      string s(n , '.');
      for(int i = 0 ; i<n ; i++){
        board[i] = s;
      }  
      vector<int> leftRow(n,0) , lowerDiagonal(2*n-1 , 0) , upperDiagonal(2*n-1 , 0);
      solve(0 , board , ans ,leftRow, lowerDiagonal ,upperDiagonal , n);
      return ans;
    }
};