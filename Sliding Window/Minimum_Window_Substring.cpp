 /*
Category: Strings, Sliding Window

Approach:
- Maintain a frequency array for characters required from string t.
- Expand the window using the right pointer:
  - If the current character is still needed, increase the matched count.
  - Decrease its frequency in the array.
- Once all characters of t are matched:
  - Shrink the window from the left as much as possible while keeping it valid.
  - Update the minimum window length whenever a smaller valid window is found.
- Continue expanding and shrinking until the entire string is processed.
- Return the smallest valid window found.

Time Complexity: O(m + n)
Space Complexity: O(1)
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(n > m) return "";
        int r = 0 , l = 0 , start = -1,count = 0;
        int len = INT_MAX;
        vector<int> freq(256,0);
        for(char ch : t) freq[ch]++;
        while(r<m){
            if(freq[s[r]] > 0){
                count++;
            }
            freq[s[r]]--;
            while(count == n){
                if((r-l+1) < len){
                    len = r-l+1;
                    start = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) count--;
                l++;

            }
            r++;
        }
        if(len == INT_MAX) return "";
        return s.substr(start,len);

    }
};