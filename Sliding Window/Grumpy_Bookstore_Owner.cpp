/*
Category: Sliding Window
Approach:
First compute baseline satisfied customers where owner is not grumpy.
Then use a fixed-size sliding window of length minutes to maximize extra satisfied customers
by converting a window of grumpy minutes into non-grumpy and tracking maximum gain.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra variables are used
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int prevloss = 0;
        int idx = 0;
        for(int i = 0 ; i<minutes ; i++){
            if(grumpy[i] == 1) prevloss += customers[i];
        }
        int maxloss = prevloss;
        int i = 1 , j = minutes;
        while(j<n){
            int currloss = prevloss;
            if(grumpy[j] == 1) currloss += customers[j];
            if(grumpy[i-1] == 1) currloss -= customers[i-1];
            if(maxloss < currloss){
                maxloss = currloss;
                idx = i;
            }
            i++;
            j++;
            prevloss = currloss;
        }
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            if(grumpy[i] == 0 || (i >= idx && i<idx + minutes)) ans += customers[i];
        }
        return ans;
    }
};