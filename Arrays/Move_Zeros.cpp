/*
Category: Two Pointers
Approach:
Maintain a pointer j for position of next non-zero element. Traverse array and whenever a non-zero
is found, swap it with position j and increment j. This keeps all non-zero elements compacted at front
while pushing zeros towards the end in-place.
Time Complexity: O(n)
Space Complexity: O(1)
Where operation is done in-place with constant extra space
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 0 ; i< n ; i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};