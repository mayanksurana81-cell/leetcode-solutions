/*
Category: Recursion / Backtracking
Approach:
Partition the string by exploring all substrings and only proceeding if the substring is a palindrome.
Backtracking builds all possible palindrome partitions.
Time Complexity: O(n * 2^n)
Space Complexity: O(n)
Where recursion depth is n and output stores all partitions
*/
class Solution {
public:
bool isPalindrome(string &s){
    if(s.length() <= 1) return true;
    int i = 0 , j = s.length()-1;
    while(i<=j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else return false;
    }
    return true;
}
    void helper(vector<vector<string>> &ans , vector<string> &s ,string &org , int i){
        if(i == org.length()){
            ans.push_back(s);
            return;
        }
        for(int j = i ; j < org.length() ; j++){
            string a = org.substr(i , j-i+1);
            if(isPalindrome(a)){
                s.push_back(a);
            helper(ans , s , org , j+1);
            s.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string org) {
        vector<vector<string>> ans;
        vector<string> s;
        helper(ans ,s ,org , 0);
        return ans;
    }
};