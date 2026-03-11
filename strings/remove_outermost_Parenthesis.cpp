/*
Category: String, Stack Simulation

Approach:
Use a counter to track the depth of parentheses.
Skip the first '(' and last ')' of each primitive substring
by only adding characters when the depth is not outermost.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int i = 0;
        string ans = "";
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] == '('){
                if(count == 0) count++;
                else{
                    count++;
                    ans += s[i];
                }
            }
            else{
                count--;
                if(count != 0) ans += s[i];
            }
        }
        return ans;
    }
};