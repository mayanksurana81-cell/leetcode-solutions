/*
Category: Prefix Sum / Binary Search
Approach:
Sort the array and convert it into prefix sum so that each index represents sum of smallest elements.
For each query, use binary search to find the maximum length such that prefix sum <= query.
Time Complexity: O(n log n + m log n)
Space Complexity: O(1)
Where sorting and binary search dominate and no extra space apart from result is used
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        sort(nums.begin() , nums.end());
        for(int i = 1 ; i< n ;i++){
            nums[i] += nums[i-1];
        }
        for(int i = 0 ; i<m ; i++){
            int max_Len = 0;
            int lo = 0 , hi = n-1;
            while(lo<=hi){
                int mid = lo + (hi - lo)/2;
                if(nums[mid] > queries[i]) hi = mid - 1;
                else{
                    max_Len = mid + 1;
                    lo = mid + 1;
                }
            }
            ans[i] = max_Len;
        }
        return ans;
    }
};