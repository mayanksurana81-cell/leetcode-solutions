/*
Category: String (Primary), Sorting (Secondary)

Approach:
Sort the array of strings. The common prefix of the whole array
must be the common prefix between the first and last strings
in the sorted order. Compare characters until they differ.

Time Complexity: O(n log n)
Space Complexity: O(1)
Where n = number of strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];
        sort(strs.begin() , strs.end());
        string &first = strs[0] , &last = strs.back();
        int i = 0 , m = min(first.length() , last.length());
        while(i<m && first[i] == last[i]){
            i++;
        }
        return first.substr(0,i);
        
    }
};