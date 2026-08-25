/*
Category: Hash Set, Array, Math

Approach:
- Store all elements of the array in an unordered_set for constant-time lookup.
- Start from k and generate its positive multiples one by one.
- Return the first multiple that does not exist in the set.

Time Complexity: O(n) average
Space Complexity: O(n)
*/
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        for(long long multiple = k; ; multiple += k){
            if(st.find(multiple) == st.end()) return multiple;
        }
        return -1;
    }
};