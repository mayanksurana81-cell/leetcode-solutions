/*
Category: Prefix Sum
Approach:
Count penalty for closing at each hour by combining number of 'N' before it and 'Y' after it.
Use prefix sum for 'N' and suffix sum for 'Y', then choose index with minimum total penalty.
Time Complexity: O(n)
Space Complexity: O(n)
Where extra arrays store prefix and suffix counts
*/
class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin() , s.end());
        int ans = 0;
        if(s[0] >= 0){
            for(int i = 0 ; i<n ; i++){
                ans += s[i]*(i+1);
            }
        }
        else{
            vector<int> suff(n);
            suff[n-1] = s[n-1];
            for(int i = n-2 ; i>=0 ;i--){
                suff[i] = suff[i+1] + s[i];
            }
            int idx = -1;
            for(int i = 0 ; i<n ; i++){
                if(suff[i] >=0){
                    idx = i;
                    break;
                }
            }
            if(idx == -1) return 0;
            int time = 1;
            for(int i = idx ; i<n ; i++){
                ans += s[i]*time;
                time++;
            }
        }
        return ans;
    }
};