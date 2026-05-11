/*
Category: Binary Search
Approach:
Use binary search on the mountain array to locate the peak element.
If current element is greater than both neighbors, it is the peak.
Otherwise move toward the increasing side since peak always lies there.
Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 1;
        int hi = n-2;
        int mid;
        while(lo<=hi){
             mid = lo + (hi-lo)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(arr[mid]>arr[mid+1]){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return mid;
    }
};