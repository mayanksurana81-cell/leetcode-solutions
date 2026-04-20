/*
Category: Array / Two Pointers
Approach:
Rotate the array by reversing entire array first, then reverse first k elements and remaining n-k elements.
This effectively shifts elements to the right by k positions in-place.
Time Complexity: O(n)
Space Complexity: O(1)
Where all operations are done in-place using constant extra space
*/
class Solution {
public:
void swap(int &a, int &b){
    int temp = a;
    a= b;
    b = temp;
}
    void reverse(vector<int> &nums , int l , int r){
        while(l<r){
            swap(nums[l] , nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);

        
    
    }
};