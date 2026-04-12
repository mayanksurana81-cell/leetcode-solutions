/*
Category: Hashing
Approach:
Use an unordered set to track seen elements and check for duplicates during iteration.
If an element already exists in the set, return true immediately.
Time Complexity: O(n)
Space Complexity: O(n)
Where set stores at most n elements
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int ele : nums){
            if(s.count(ele)) return true;
            s.insert(ele);
        }
        return false;
    }
};