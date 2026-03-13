/*
Category: String (Primary), Hashing (Secondary)

Approach:
Store Roman numeral values in a hashmap. Traverse the string
and compare the current value with the next one. If the current
value is smaller, subtract it (subtractive notation), otherwise add it.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = length of the string.
*/
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char , int>mp = {
            {'I' , 1}, {'V' , 5}, {'X' , 10}, {'L' , 50}, {'C' , 100}, {'D' , 500}, {'M' , 1000}
        };
        for(int i = 0 ; i<n ; i++){
            if(i+1 < n && mp[s[i]] < mp[s[i+1]]) ans -= mp[s[i]];
            else ans += mp[s[i]];
        }
        return ans;
    }
};