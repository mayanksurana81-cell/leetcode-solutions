 /*
Category: Strings, ASCII Mapping

Approach:
- Use an array indexed by ASCII values to store character positions.
- Traverse the string:
  - Store the latest index for lowercase letters.
  - For uppercase letters, only store the first occurrence.
- After processing:
  - Iterate through uppercase letters 'A' to 'Z'.
  - A character is considered special if:
    - Both uppercase and lowercase versions exist.
    - The uppercase letter appears after the lowercase letter.
- ASCII difference of 32 is used to map uppercase letters to lowercase letters.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        int count = 0;
        vector<int> v(123 , -1);
        for(int i = 0 ; i<n ; i++){
            int pos = (int)word[i];
            if(pos < 91 && v[pos] != -1) continue;
            if(v[pos] < i) v[pos] = i;
        }
        for(int j = 65 ; j<91 ; j++){
            if(v[j] == -1) continue;
            if(v[j+32] != -1 && v[j] > v[j+32]) count++;
        }
        return count;
    }
};