/*
Category: Sorting, Two Pointers, Array, Duplicate Handling

Approach:
- Sort the array and fix the first two elements using nested loops.
- Use pruning conditions to skip impossible ranges based on the smallest and largest possible sums.
- For each fixed pair, use two pointers from both ends of the remaining range to find pairs completing the target sum.
- Skip duplicate values for i, j, lo, and hi to ensure unique quadruplets.
- Use long long for sum calculations to avoid integer overflow.

Time Complexity: O(n^3)
Space Complexity: O(1) excluding the output vector
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i++){
            if((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                long long sum = (long long)nums[i] + nums[j];
                int lo = j + 1, hi = nums.size() - 1;
                while(lo < hi){
                    long long sum_4 = sum + nums[lo] + nums[hi];
                    if(sum_4 == target){
                        ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++;
                        hi--;
                    }
                    else if(sum_4 < target) lo++;
                    else hi--;
                }
            }
        }
        return ans;
    }
};