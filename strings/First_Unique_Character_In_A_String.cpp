 /*
Category: Strings, Hashing

Approach:
- Count the frequency of each character using a frequency array of size 26.
- Traverse the string once to build the frequency counts.
- Traverse the string again from left to right.
- The first character whose frequency is exactly 1 is the first non-repeating character.
- Return its index; if no such character exists, return -1.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> freq(26);
        for(char ch : s){
            freq[ch - 'a']++;
        }
        int ans = -1;
        for(int i = 0; i<n; i++){
            int idx = s[i] - 'a';
            if(freq[idx] == 1){
                ans = i;
                break;
            }
        }
    return ans;
    }
};