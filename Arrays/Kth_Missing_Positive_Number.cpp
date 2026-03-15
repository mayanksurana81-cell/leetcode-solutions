/*
Category: Array (Primary)

Approach:
Traverse the array and adjust k whenever an element
is less than or equal to the current k. This shifts
the target forward to account for existing numbers
until the kth missing positive is determined.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of elements in the array.
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int  i = 0 ; i < n ; i++){
            if(arr[i] <= k) k++;
            else break;
        }
        return k;
    }
};