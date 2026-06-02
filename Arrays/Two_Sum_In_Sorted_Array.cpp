 /*
Category: Arrays, Two Pointers

Approach:
- Since the array is sorted, use two pointers:
  - i starting from the beginning.
  - j starting from the end.
- Calculate the sum of the elements at both pointers.
- If the sum equals the target, return their 1-based indices.
- If the sum is greater than the target, move the right pointer leftward.
- If the sum is smaller than the target, move the left pointer rightward.
- Continue until the required pair is found.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;

        while(i < j) {
            if(numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
            else if(numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }

        return {-1, -1};
    }
};