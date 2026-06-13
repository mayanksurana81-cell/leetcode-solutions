 /*
Category: Bit Manipulation, Prefix Sum

Approach:
- Build a prefix XOR array where prefix[i] stores the XOR of all elements
  from index 0 to i.
- For each query [l, r]:
  - If l is 0, the answer is prefix[r].
  - Otherwise, XORing prefix[r] with prefix[l-1] cancels out the elements
    before l, leaving the XOR of the range [l, r].
- Process all queries using the precomputed prefix XOR array.

Time Complexity: O(n + q)
Space Complexity: O(n)
 */
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i <n; i++){
            prefix[i] = prefix[i-1]^arr[i];
        }
        vector<int> ans;
        for(auto &q : queries) {
            int l = q[0];
            int r = q[1];
            if(l == 0)
                ans.push_back(prefix[r]);
            else
                ans.push_back(prefix[r] ^ prefix[l - 1]);
        }
        return ans;
    }
};