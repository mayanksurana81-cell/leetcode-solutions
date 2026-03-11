/*
Category: String (Primary), Greedy (Secondary)

Approach:
Traverse the string from right to left to find the first odd digit.
The substring from index 0 to that position forms the largest odd number.

Time Complexity: O(n)
Space Complexity: O(1)
Where n = length of the string.
*/
class Solution {
public:
    string largestOddNumber(string s) {
        int n= s.length();
        int lastodd = -1;
        int i = n-1;
        for(int i = n-1 ; i>=0 ; i--){
            if((s[i] - '0') % 2 != 0){
                lastodd = i;
                break;
            } 
        }
        return lastodd == -1 ? "" : s.substr(0,lastodd+1);
    }
};