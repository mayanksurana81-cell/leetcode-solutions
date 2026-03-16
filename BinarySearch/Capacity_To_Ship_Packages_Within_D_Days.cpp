/*
Category: Array (Primary), Binary Search on Answer (Secondary)

Approach:
Binary search the minimum ship capacity. For a given capacity,
simulate loading packages sequentially and count the number
of days required. If days exceed the limit, increase capacity;
otherwise try a smaller capacity.

Time Complexity: O(n log S)
Space Complexity: O(1)

Where n = number of packages,
      S = sum of all weights.
*/
class Solution {
public:
long long check(vector<int>& weights, int weight){
    int days = 0;
    long long sum = 0;
    for(int i = 0 ; i < weights.size() ; i++){
        sum += weights[i];
        if(sum > weight){
            days++;
            sum = 0;
            i--;
        }
    }
    return days+1;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int high = *max_element(weights.begin() , weights.end());
        long long sum = 0L;
        for(int ele : weights) sum += ele;
        int i = high , j = sum;
        while(i<=j){
            int mid = i + (j-i)/2;
            int d = check(weights , mid);
            if(d <= days) j = mid-1;
            else i = mid + 1;
        }
        return i;
    }
};