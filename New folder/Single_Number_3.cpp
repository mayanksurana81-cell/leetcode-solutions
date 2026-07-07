 /*
Category: Bit Manipulation

Approach:
- XOR all elements of the array.
- Since every duplicate number appears twice, they cancel out, leaving:
  firstUnique XOR secondUnique.
- Find the rightmost set bit in this XOR result.
- This bit differs between the two unique numbers, so use it to divide
  the array into two groups.
- XOR all numbers within each group separately.
- Duplicate numbers cancel out within their respective groups, leaving
  the two unique numbers as the final results.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int res = 0;
        for(auto x : nums) res ^= x;
        unsigned int unique = (unsigned int) res & -(unsigned int)res;
        int v1 = 0, v2 = 0;
        for(int i = 0; i <n; i++){
            if(nums[i] & unique){
                v1 ^= nums[i];
            }
            else v2 ^= nums[i];
        }
        return {v1,v2};
    }
};
