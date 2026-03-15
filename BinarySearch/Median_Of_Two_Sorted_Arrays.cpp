/*
Category: Array (Primary), Binary Search (Secondary)

Approach:
Use binary search on the smaller array to find a valid partition
between the two arrays such that elements on the left side are
less than or equal to those on the right side. Once the correct
partition is found, compute the median based on total length.

Time Complexity: O(log(min(n1, n2)))
Space Complexity: O(1)

Where n1 = size of first array,
      n2 = size of second array.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        if(n1>n2) return findMedianSortedArrays(b,a);
        int n = n1+n2;
        int left = (n1+n2+1)/2;
        int i = 0 , j = n1;
        while(i<=j){
            int mid1 = i + (j-i)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            if(mid1 - 1 >=0 ) l1 = a[mid1-1];
            if(mid2 - 1 >= 0) l2 = b[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2 != 0) return max(l1,l2);
                else return (double)(max(l1,l2) + min(r1,r2))/2.0;
            }
            else if(l1 > r2) j = mid1-1;
            else i = mid1 + 1;
        }
        return 0;
    }
};