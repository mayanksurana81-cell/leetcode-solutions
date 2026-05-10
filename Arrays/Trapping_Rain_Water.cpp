/*
Category: Array / Prefix Maximum
Approach:
Store the minimum boundary height available for each index using left and right maximums.
First pass stores maximum height from left, second pass updates with smaller right maximum,
then trapped water at each index is calculated as boundary height minus current height.
Time Complexity: O(n)
Space Complexity: O(n)
Where extra array stores effective water boundaries for each index
*/
class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size();
    int prev[n];
    prev[0] = -1;
    int max = height[0];
    for(int i = 1 ;i<n ; i++){
        prev[i] = max;
        if(max<height[i]) max = height[i];
    }      
    prev[n-1] = -1;
    max = height[n-1];
    for(int i = n-2 ; i>=0 ; i--){
        if(max<prev[i])prev[i] = max;
        if(max<height[i]) max = height[i];
    }
    int water = 0;
    for(int i = 1 ; i<n-1 ; i++){
        if(height[i]<prev[i]){
        water = water + (prev[i] - height[i]);}
    }
    return water;

    }
};