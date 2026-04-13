/*
Category: Recursion / Backtracking
Approach:
Map each digit to corresponding characters and recursively build all combinations.
At each index, try all mapped characters and backtrack to explore all possibilities.
Time Complexity: O(4^n)
Space Complexity: O(n)
Where recursion depth is n and output stores all combinations
*/
class Solution {
public:
vector<string> ans;
void helper(int i , string &s , string &digits ,unordered_map<char , string>&mp){
    if(i == digits.length()){
        ans.push_back(s);
        return;
    }
    char ch = digits[i];
    for(char t : mp[ch]){
        s+=t;
        helper(i+1 , s, digits , mp);
        s.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;
        unordered_map<char , string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string s = "";
        helper(0 , s , digits , mp);
        return ans;
    }
};