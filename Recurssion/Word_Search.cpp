/*
Category: Backtracking / DFS
Approach:
Start DFS from every cell that matches the first character of the word. From each position,
explore all 4 possible directions while checking bounds and matching characters.
Mark the current cell as visited to avoid reuse in the same path, and backtrack by restoring it after exploration.
If all characters of the word are matched (idx reaches length), return true.
Time Complexity: O(m * n * 4^L)
Space Complexity: O(L)
Where m,n are grid dimensions and L is length of the word (recursion depth)
*/
class Solution {
public:
    int m , n;
    vector<vector<int>> dir = {{1,0} , {-1 , 0} , {0,1} , {0,-1}};
    bool find(vector<vector<char>>& board , string &word , int i , int j , int idx){
        if(idx == word.length()) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] == '$' || board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &d : dir){
            int new_i = i+d[0];
            int new_j = j+d[1];
            if(find(board , word , new_i , new_j , idx+1)) return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(board[i][j] == word[0] && find(board , word , i , j , 0)) return true;
            }
        }
        return false;
    }
};