/*
Category: Recursion / Backtracking
Approach:
Use recursion to build all valid parentheses strings by adding '(' and ')' while maintaining balance. 
Ensure at any step that closing brackets do not exceed opening ones and only add ')' when valid.
Time Complexity: O(2^n)
Space Complexity: O(n)
Where n is the number of pairs of parentheses
*/
class Solution {
public:
    void helper(vector<string> &ans , string s , int o , int c){
        if(o == 0 && c == 0){
            ans.push_back(s);
            return;
        }
       if(o>0)helper(ans , s + '(' , o-1 , c);
        if(o == 0 || c > o){
            helper(ans ,s + ')' , o , c-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans , "" ,n ,n);
        return ans;
    }
};