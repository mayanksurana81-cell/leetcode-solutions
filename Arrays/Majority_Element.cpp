/*
Category: Greedy / Boyer-Moore Voting
Approach:
Maintain a candidate element and a counter. If current element matches candidate, increment count,
otherwise decrement; when count becomes zero, update candidate to current element.
This works because majority element appears more than n/2 times and dominates cancellations.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
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