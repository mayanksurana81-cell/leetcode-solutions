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
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> preN(n+1);
        preN[0] = 0;
        vector<int> sufY(n+1);
        sufY[n] = 0;
        for(int i = 0 ; i<n ; i++){
            if(customers[i] == 'N'){
                preN[i+1] = preN[i] + 1;
            }
            else preN[i+1] = preN[i];
        }
        for(int i = n-1 ; i>=0 ; i--){
            if(customers[i] == 'Y'){
                sufY[i] = sufY[i+1] + 1;
            }
            else sufY[i] = sufY[i+1];
        }
        int min = INT_MAX;
        int idx = -1;
        for(int i = 0 ; i<n+1 ; i++){
            preN[i] = preN[i] + sufY[i];
            if(preN[i] < min){
                min = preN[i];
                idx = i;
            }
        }
        return idx;

    }
};