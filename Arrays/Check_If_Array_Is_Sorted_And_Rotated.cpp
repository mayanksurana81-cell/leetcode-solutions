/*
Category: Array
Approach:
Count number of places where the order breaks (nums[i] > nums[i+1]).
If more than one such break exists, it's not sorted-rotated. If exactly one,
also ensure last element is not greater than first to validate rotation.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()<=1) return true;
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i< nums.size()-1 ; i++){
            if(nums[i] > nums[i+1]){
                count++;
                if(count>1) return false;
            }
        }
        if(count == 1 && nums[n-1] > nums[0]) return false;
        return true;
    }
};
