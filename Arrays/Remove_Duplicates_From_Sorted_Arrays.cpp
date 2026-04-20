/*
Category: Two Pointers
Approach:
Maintain pointer i for last unique element and iterate j through array.
Whenever a new unique element is found, increment i and place it at position i.
Time Complexity: O(n)
Space Complexity: O(1)
Where duplicates are removed in-place using constant space
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1 ; j<nums.size() ; j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};