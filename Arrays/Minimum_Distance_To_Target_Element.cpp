/*
Category: Array / Brute Force
Approach:
Traverse the array and check all indices where element equals target.
Compute absolute distance from start and keep track of minimum distance.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
*/
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == target){
                mini = min(mini , abs(i - start));
            }
        }
        return mini;
    }
};