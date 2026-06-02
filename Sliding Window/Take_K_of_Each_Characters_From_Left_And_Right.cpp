 /*
Category: Strings, Sliding Window

Approach:
- Count the total occurrences of 'a', 'b', and 'c' in the string.
- If any character appears fewer than k times, it is impossible to satisfy
  the requirement, so return -1.
- Instead of choosing characters from both ends, find the longest middle
  substring that can be left untouched.
- Use a sliding window:
  - Remove window characters from the frequency counts.
  - If any remaining character count becomes less than k, shrink the window.
- Track the maximum valid window length.
- The minimum number of characters taken from the ends is:
  total length - longest valid window length.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int winlen = -1;
        vector<int> freq(3);
        for(char ch : s) freq[ch-'a']++;
        if(*min_element(freq.begin() , freq.end()) < k) return -1;
        int i = 0 , j = 0;
        while(j < n){
            freq[s[j] - 'a']--;
            while(*min_element(freq.begin() , freq.end()) < k){
                freq[s[i] - 'a']++;
                i++;
            }
            winlen = max(winlen , j-i +1);
            j++;
        }
        return (winlen == -1) ? -1 : n-winlen;
    }
};