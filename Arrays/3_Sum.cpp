 /*
Category: Arrays, Sorting, Two Pointers

Approach:
- Sort the array to enable efficient duplicate handling and two-pointer traversal.
- Fix one element at index i and search for two other elements whose sum equals -nums[i].
- Use two pointers:
  - j starting just after i.
  - k starting from the end of the array.
- If the current triplet sum is too large, move k left.
- If the sum is too small, move j right.
- If the sum is zero:
  - Store the triplet.
  - Move both pointers while skipping duplicate values to avoid repeated triplets.
- Also skip duplicate values for the fixed element i.

Time Complexity: O(n²)
Space Complexity: O(1)
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i<nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1 , k = nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--;
                else if(sum < 0) j++;
                else{
                    vector<int> temp = {nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};