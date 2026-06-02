 /*
Category: Strings, Sliding Window, Hash Map

Approach:
- Store the frequency of all words in a hash map.
- Since all words have the same length, process the string using multiple
  sliding windows starting from offsets 0 to wordLength-1.
- Move the window in chunks of wordLength and extract words from the string.
- If the extracted word exists in the target map:
  - Add it to the current window frequency map.
  - If its frequency exceeds the allowed count, shrink the window from the left.
- When the window contains exactly the required number of words,
  record the starting index.
- If an invalid word is encountered, reset the window and start fresh.

Time Complexity: O(n × wordLength)
Space Complexity: O(m)

Where m is the number of distinct words.
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for (string &w : words)
            mp[w]++;

        vector<int> ans;

        int len = words[0].length();
        int totalWords = words.size();

        for (int i = 0; i < len; i++) {
            int left = i;
            int count = 0;

            unordered_map<string,int> winmap;

            for (int right = i; right + len <= s.size(); right += len) {

                string temp = s.substr(right, len);

                if (mp.count(temp)) {

                    winmap[temp]++;
                    count++;

                    while (winmap[temp] > mp[temp]) {
                        string leftWord = s.substr(left, len);
                        winmap[leftWord]--;
                        count--;
                        left += len;
                    }

                    if (count == totalWords) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, len);
                        winmap[leftWord]--;
                        count--;
                        left += len;
                    }
                }
                else {
                    winmap.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return ans;
    }
};