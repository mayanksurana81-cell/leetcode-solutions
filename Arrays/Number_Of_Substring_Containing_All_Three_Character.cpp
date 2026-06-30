/*
Category: Sliding Window, Hash Map

Approach:
- Use a sliding window to maintain the current substring.
- Decrease the required count for each character as the right pointer expands.
- Once the window contains at least one 'a', 'b', and 'c', every extension of this window to the right also remains valid.
- Add all such substrings at once using (n - j), then shrink the window from the left to find more valid starting positions.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        mp['a'] = 1 , mp['b'] = 1, mp['c'] = 1;
        int count = 0 ;
        int i = 0 , j = 0;
        while(j < n){
            mp[s[j]]--;
            while(mp['a'] <= 0 && mp['b'] <= 0 && mp['c'] <= 0){
                count += n - j;
                mp[s[i]]++;
                i++;
            }
            j++;
        }
    return count;
    }
};