/*
Category: String (Primary), Hashing (Secondary)

Approach:
Use two arrays to store the last seen index of characters
from both strings. If the last seen positions differ,
the mapping is inconsistent → not isomorphic.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = length of the string.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {} , m2[256] = {};
        for(int i = 0 ; i<(int)s.length() ; i++){
            if(m1[s[i]] != m2[t[i]]) return false;
            else m1[s[i]] = m2[t[i]] = i+1;
        }
        return true;
    }
};