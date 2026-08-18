/*
Category: Sliding Window, Two Pointers, Frequency Array

Approach:
- Maintain a sliding window [i, j] and track the frequency of each character inside it.
- max_freq stores the highest character frequency seen while expanding the window.
- The number of replacements needed is the window length minus max_freq.
- If replacements are within k, expand the window and update the maximum length.
- Otherwise, shrink the window from the left until it becomes valid again.
- The window expansion is controlled by j_moves so that the right-side character is not counted twice when the window is shrinking.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = 0;
        int i = 0 , j = 0;
        int max_freq = 0;
        vector<int> freq(26);
        bool j_moves = true;
        while(j < s.length()){
            if(j_moves)freq[s[j] - 'A']++;
            if(freq[s[j] - 'A'] > max_freq) max_freq = freq[s[j] - 'A'];
            if((j - i + 1) - max_freq <= k) {
                len = max(len, j - i + 1);
                j++;
                j_moves = true;
            }
            else{
                freq[s[i] - 'A']--;
                i++;
                j_moves = false;
            }
        }
        return len;
    }
};