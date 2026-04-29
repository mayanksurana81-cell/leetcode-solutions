/*
Category: Hashing / Math
Approach:
Insert each number and its reversed value into a set to ensure uniqueness.
Final size of the set gives count of distinct integers after considering reversals.
Time Complexity: O(n * d)
Space Complexity: O(n)
Where d is number of digits and set stores unique values
*/
class Solution {
public:
    int reverse(int n){
        int r = 0;
        while(n>0){
        r *= 10;
        r +=(n%10);
        n /= 10;
        }
        return r;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
         unordered_set<int> s;
        for(int i = 0 ; i<n; i++){
            s.insert(nums[i]);
            int rev = reverse(nums[i]);
            s.insert(rev);
        }
        
        return s.size();
    }
};