/*
Category: Array (Primary), Boyer-Moore Voting (Secondary)

Approach:
Use Boyer-Moore Voting Algorithm to find the majority element.
Maintain a candidate and count; increment for same element,
decrement for different, and update candidate when count becomes zero.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int element = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == element){
                count++;
            }
            else{
                if(count == 0){
                    element = nums[i];
                    count++;
                }
               else count--;
            }
        }
        return element;
    }
};