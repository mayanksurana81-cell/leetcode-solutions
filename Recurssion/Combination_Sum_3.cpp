
/*
Category: Recursion / Backtracking
Approach:
Generate combinations of size k using numbers 1–9 such that their sum equals n.
Use backtracking with pruning when sum exceeds or size limit is reached.
Time Complexity: O(2^9)
Space Complexity: O(k)
Where recursion depth is at most k
*/
class Solution {
public:
void helper(vector<vector<int>> &ans ,vector<int> &v , int k , int n , int start){
    if(n == 0 && v.size() == k){
        ans.push_back(v);
        return;
    }
    if(n == 0 || v.size() >= k) return;
    for(int i = start; i<=9 ; i++){
        if(n<= 0) break;
        v.push_back(i);
        helper(ans , v , k , n-i , i+1);
        v.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans , v , k , n ,1);
        return ans;
    }
};