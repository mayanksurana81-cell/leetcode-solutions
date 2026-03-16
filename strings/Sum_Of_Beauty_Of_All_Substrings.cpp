/*
Category: String (Primary), Brute Force / Frequency Count (Secondary)

Approach:
Generate all substrings using two loops. Maintain a frequency
array for characters in the current substring and compute the
difference between the maximum and minimum occurring characters
to accumulate the beauty value.

Time Complexity: O(n^2 * 26)
Space Complexity: O(26) ≈ O(1)

Where n = length of the string.
*/
class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for(int i = 0 ; i< n ; i++){
            vector<int>freq(26,0);
                for(int j = i ;j< n ; j++){

                    freq[s[j] - 'a']++;

                    int mx = INT_MIN;
                    int mn = INT_MAX;

                        for(int k = 0 ; k<26 ; k++){
                            if(freq[k] > 0){
                                mx = max(mx , freq[k]);
                                mn = min(mn , freq[k]);
                            }
                        }
                        sum += mx - mn;
                }
        }
        return sum;
        
    }
};