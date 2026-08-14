/*
Category: Prefix Sum, Hash Map

Approach:
- Maintain a running prefix sum and compute its remainder when divided by k.
- If two prefix sums have the same remainder, the subarray between them has a sum divisible by k.
- Store the frequency of each remainder in a hash map and add its previous frequency to the count whenever the same remainder is encountered.
- Normalize negative remainders to keep them within the range [0, k-1].

Time Complexity: O(n)
Space Complexity: O(k)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        int presum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
           presum += nums[i];
           int rem = presum % k;
           if(rem < 0) rem += k;
           cnt += mp[rem];
           mp[rem] += 1;
        }
        return cnt;
    }
};