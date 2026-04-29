/*
Category: Hashing / Strings
Approach:
Use a set to store seen strings. For each string, check if its reverse already exists in the set.
If yes, increment count, otherwise insert the current string.
Time Complexity: O(n * k)
Space Complexity: O(n * k)
Where k is length of strings and set stores all seen strings
*/
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int n = arr.size();
         unordered_set<string> s;
        int count = 0;
        for(int i = 0 ; i<n ; i++){
            string rev = arr[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev) != s.end()) count++;
            else s.insert(arr[i]);
        }
       
        return count;
    }
};