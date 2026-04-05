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
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int c1 = 0 , c2 = 0;
       int n = nums.size();
       for(int i = 0 ; i< n ; i++){
        if(nums[i] == 1){
            c1++;
        }
        else{
            c2 = max(c1,c2);
            c1 = 0;
        }
       }
        return max(c1,c2);
    }
};