/*
Category: Array (Primary), Binary Search on Answer (Secondary)

Approach:
Binary search the minimum day required to make m bouquets.
For a given day, check if we can form bouquets by counting
k consecutive flowers that bloom on or before that day.
If possible, try a smaller day; otherwise increase the day.

Time Complexity: O(n log D)
Space Complexity: O(1)

Where n = number of flowers,
      D = range of bloom days.
*/
class Solution {
public:
bool isPossible(vector<int>& bloomDay, int day,int m, int k){
    int cnt = 0 , bq = 0;
    for(int ele : bloomDay){
        if(day >= ele){
            cnt++;
            if(cnt==k){
                bq++;
                cnt = 0;
            }
        }
        else cnt = 0;
    }
    return bq>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long total_flowers = 1L*m*k;
        if(total_flowers > n) return -1;
        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin() , bloomDay.end());
        int i = low , j = high;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(isPossible(bloomDay , mid , m,k)) j = mid-1;
            else i = mid + 1;
        }
        return i;
    }
};