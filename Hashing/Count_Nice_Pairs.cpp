/*
Category: Hashing / Math
Approach:
Transform each number into (num - reverse(num)) so that valid pairs have equal transformed values.
Use a hashmap to count frequencies and for each element add existing count to answer.
Time Complexity: O(n * d)
Space Complexity: O(n)
Where d is number of digits for reversing and map stores frequencies
*/
class Solution {
public:
int rev(int n){
    int r = 0;
    while(n>0){
        r*=10;
        r += n%10;
        n /= 10;
    }
    return r;
}
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>m;
        for(int i = 0; i<n ; i++) {
            int x = nums[i] - rev(nums[i]);
            if(m.find(x)!=m.end()){
                count = count % 1000000007;
                count += m[x];
                m[x]++;
            }
            else{
                m[x]++;
            }
        }
        return count%1000000007;
    }
};