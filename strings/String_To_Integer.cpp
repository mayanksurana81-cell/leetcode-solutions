/*
Category: String (Primary), Parsing (Secondary)

Approach:
Skip leading spaces, determine the sign, then convert
continuous digits into an integer. During conversion,
check for overflow and clamp the result to INT_MAX or
INT_MIN when limits are exceeded.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = length of the string.
*/
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long ans = 0;
        int sign = 1;
        int i = 0;
        while(i<n && s[i] == ' ') i++;

        if(i < n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            ans = ans*10 + (s[i] - '0');

            if(sign * ans > INT_MAX) return INT_MAX;
            else if(sign * ans < INT_MIN) return INT_MIN;

            i++;
        }
        return sign*ans;
    }
};