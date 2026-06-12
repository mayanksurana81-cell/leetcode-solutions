 /*
Category: Arrays, Sliding Window, Hash Map

Approach:
- Maintain a sliding window that contains at most two distinct fruit types.
- Expand the window by moving the right pointer and adding fruits to the frequency map.
- If the window contains more than two distinct fruit types:
  - Shrink it from the left.
  - Decrease frequencies and remove fruit types whose count becomes zero.
- After ensuring the window contains at most two distinct types, update the maximum window length.
- The maximum valid window length represents the maximum number of fruits that can be collected.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int j = 0, i = 0,maxLen = 0;
        unordered_map<int,int> mp;
        while(j < n){
            mp[fruits[j]]++;
            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};