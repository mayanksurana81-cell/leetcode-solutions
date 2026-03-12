/*
Category: String (Primary), Hashing (Secondary)

Approach:
Use a frequency array of size 26 for lowercase letters.
Increment count for characters in s and decrement for t.
If all frequencies become zero, both strings are anagrams.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = length of the string.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int freqarray[26] = {0};
        for(int i = 0 ; i<s.length() ; i++){
            freqarray[s[i] - 'a']++;
            freqarray[t[i] - 'a']--;
        }
        for(int i = 0 ; i<26 ; i++){
            if(freqarray[i] != 0) return false;
        }
        return true;
        
    }
};