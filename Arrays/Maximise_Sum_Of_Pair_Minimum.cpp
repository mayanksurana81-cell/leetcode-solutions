 /*
Category: Arrays, Sorting, Greedy

Approach:
- Sort the array in non-decreasing order.
- Form pairs using adjacent elements in the sorted array.
- In each pair, the smaller element contributes to the final sum.
- Since the array is sorted, these smaller elements occur at even indices.
- Add all elements at even indices to obtain the maximum possible sum of pair minimums.

Time Complexity: O(n log n)
Space Complexity: O(1)
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i+=2){
            sum += nums[i];
        }
        return sum;
    }
};