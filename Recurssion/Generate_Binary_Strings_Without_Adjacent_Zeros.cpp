/*
Category: Recursion / Backtracking
Approach:
Generate binary strings ensuring no consecutive '0's by appending '1' always and '0' only if last character is not '0'.
Uses recursive construction with constraint checking at each step.
Time Complexity: O(2^n)
Space Complexity: O(n)
Where recursion depth is n and output size is bounded by valid strings
*/
class Solution {
public:
void helper(vector<string> &ans , string s , int n){
    if(n == 0){
        ans.push_back(s);
        return;
    }
    helper(ans , s + '1' , n-1);
    if(s.empty() || s.back() != '0'){
        helper(ans , s + '0' , n-1);
    }
}
    vector<string> validStrings(int n) {
       vector<string> ans;
       helper(ans , "" , n);
       return ans; 
    }
};