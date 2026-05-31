 /*
Category: Arrays, Sliding Window

Approach:
- Use the observation:
  - Subarrays with exactly k distinct elements =
    Subarrays with at most k distinct elements -
    Subarrays with at most (k-1) distinct elements.
- The helper function counts subarrays having at most k distinct elements.
- Maintain a sliding window with a frequency array and a count of distinct elements.
- Expand the window using the right pointer.
- If distinct elements exceed k, shrink the window from the left until it becomes valid.
- For every valid window, add (right - left + 1) to the answer since all subarrays
  ending at right and starting within the window are valid.

Time Complexity: O(n)
Space Complexity: O(n)
 */
class Solution {
public:
int solve(vector<int>& nums, int k){
    int n = nums.size();
        vector<int> freq(n+1);
        int count = 0 , ans = 0;
        int left = 0,right = 0;
        while(right < n){
            if(freq[nums[right]] == 0){
                count++;
            }
            freq[nums[right]]++;
            while(count > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) count--;
                left++;
            }
            ans += right - left + 1;
            right++;
}
return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums , k-1);
    }
};