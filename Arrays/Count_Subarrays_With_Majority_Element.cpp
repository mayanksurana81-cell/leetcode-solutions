/*
Category: Arrays, Brute Force, Enumeration

Approach:
- Iterate over all possible subarrays using two nested loops.
- For each starting index, extend the subarray one element at a time and maintain the frequency of the target element within the current subarray.
- After adding each element, check whether the target frequency is greater than half of the current subarray length.
- If the target appears more than half the time, count that subarray as a majority subarray.

Time Complexity: O(n²)
Space Complexity: O(1)
*/
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i; j <n; j++){
                if(nums[j] == target) cnt++;
                if(cnt > (j - i + 1)/2) count++;
            }
        }
        return count;
    }
};