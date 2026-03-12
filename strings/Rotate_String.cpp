/*
Category: String (Primary)

Approach:
If two strings are rotations, the goal string must appear
as a substring of s+s. Double the original string and
check if goal exists inside it.

Time Complexity: O(n)
Space Complexity: O(n)

Where n = length of the string.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string doubleds = s+s;
        return doubleds.find(goal) != string :: npos;

    }
};