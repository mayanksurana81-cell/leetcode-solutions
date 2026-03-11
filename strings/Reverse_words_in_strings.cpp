/*
Category: String (Primary), Two Pointers (Secondary)

Approach:
First reverse the entire string. Then iterate through the string and
extract each word separated by spaces. Reverse each extracted word
and append it to the result string while skipping extra spaces.

Time Complexity: O(n)
Space Complexity: O(n)
Where n = length of the string.
*/
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin() , s.end());
        for(int i = 0 ; i<s.length() ; i++){
            string word = "";
            while(i<s.length() && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin() , word.end());
            if(word.length()>0) ans = ans + " " + word;
        }
        return ans.substr(1);
    }
};