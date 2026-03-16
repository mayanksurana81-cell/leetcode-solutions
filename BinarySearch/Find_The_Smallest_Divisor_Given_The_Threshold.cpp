/*
Category: Array (Primary), Binary Search on Answer (Secondary)

Approach:
Binary search the smallest possible divisor. For a candidate
divisor, compute the required sum using ceil division for
each element. If the total is within k, try a smaller divisor;
otherwise increase the divisor.

Time Complexity: O(n log M)
Space Complexity: O(1)

Where n = number of elements,
      M = maximum value in the array.
*/
class Solution {
public:
    long long check(vector<int>& nums, int mid){
        long long sum = 0;
        for(int ele : nums){
            sum += (ele + mid-1)/mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int k) {
        int n = nums.size();
        int high = *max_element(nums.begin() , nums.end());
        int i = 1 , j = high;
        while(i<=j){
            int mid = i + (j-i)/2;
           long long val = check(nums, mid);
           if(val<=k) j = mid-1;
           else i = mid + 1;
        }
        return i;
    }
};