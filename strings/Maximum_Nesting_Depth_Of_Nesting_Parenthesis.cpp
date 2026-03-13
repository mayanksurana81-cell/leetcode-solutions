/*
Category: String (Primary), Stack/Parentheses (Secondary)

Approach:
Traverse the string and track currently open parentheses.
Increase count for '(' and decrease for ')'.
The maximum value reached represents the maximum nesting depth.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = length of the string.
*/
class Solution {
public:
    int maxDepth(string s) {
       int currOpen = 0;
       int ans = 0;
       for(int i = 0 ; i<s.length() ; i++){
        if(s[i] == '('){
            currOpen++;
            if(currOpen >= ans) ans = currOpen;
        }
        else if(s[i] == ')')currOpen--;
       } 
       return ans;
    }
};