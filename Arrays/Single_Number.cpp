/*
Category: Array (Primary), Bit Manipulation (Secondary)

Approach:
Use XOR operation. Since a ^ a = 0 and a ^ 0 = a,
all duplicate elements cancel out, leaving the single number.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int ele : nums){
            xr ^= ele;
        }
        return xr;
    }
};