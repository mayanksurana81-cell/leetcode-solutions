/*
Category: Sliding Window, Frequency Array, String

Approach:
- Build a frequency array for all characters in p.
- Maintain a fixed-size sliding window of length p in s and track the character frequencies inside it.
- Compare the window frequency array with p's frequency array to detect an anagram.
- Whenever the frequencies match, store the starting index of the current window.
- Move the window forward by removing the leftmost character and adding the next character.

Time Complexity: O(n × 26)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();
        if(n1 < n2) return {};
        vector<int> freq(26);
        for(char ch : p) freq[ch - 'a']++;
        vector<int> window_freq(26);
        vector<int> ans;
        int i = 0, j = n2 - 1;
        for(int k = i; k <= j; k++) window_freq[s[k] - 'a']++;
        while(j < n1){
            if(freq == window_freq) ans.push_back(i);
            window_freq[s[i]-'a']--;
            i++;
            j++;
            if(j < n1) window_freq[s[j]-'a']++;
        }
        return ans;
    }
};