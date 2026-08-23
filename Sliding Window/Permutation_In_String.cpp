/*
Category: Sliding Window, Frequency Array, String

Approach:
- Build a frequency array for all characters in s1.
- Maintain a fixed-size sliding window of length s1 in s2 and track its character frequencies.
- Compare the window frequency array with s1's frequency array for every window.
- If they match, the current window is a permutation of s1.
- Otherwise, remove the leftmost character and add the next character while moving the window forward.

Time Complexity: O(n × 26)
Space Complexity: O(1)
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n2 < n1) return false;
        vector<int> freq(26);
        for(char ch : s1) freq[ch - 'a']++;
        vector<int> window_freq(26);
        int i = 0, j = n1 - 1;
        for(int k = i; k <= j; k++) window_freq[s2[k]-'a']++;
        while(j < n2){
            if(window_freq == freq) return true;
            else window_freq[s2[i]-'a']--;
            i++;
            j++;
            if(j < n2)window_freq[s2[j]-'a']++;
        }
        return false;
    }
};