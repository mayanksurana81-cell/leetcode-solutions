/*
Category: Array (Primary)

Approach:
Traverse the array and count consecutive 1s.
Reset count when 0 appears and track the maximum count.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s1 = (n*(n+1))/2;
        int s2 = 0;
        for(int ele : nums){
            s2 += ele;
        }
        return s1-s2;
    }
};