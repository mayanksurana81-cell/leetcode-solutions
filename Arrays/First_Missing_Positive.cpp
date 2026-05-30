 /*
Category: Arrays, Cyclic Sort

Approach:
- Place every positive number x in the range [1, n] at its correct index x-1.
- Traverse the array and repeatedly swap elements until each valid number
  is either in its correct position or cannot be placed.
- After rearrangement:
  - The value at index i should be i+1.
  - The first index where this condition fails gives the smallest missing positive.
- If all positions contain the correct values, the answer is n+1.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1] , nums[i]);
            }
        }
        for(int i = 0 ; i<n ; i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};