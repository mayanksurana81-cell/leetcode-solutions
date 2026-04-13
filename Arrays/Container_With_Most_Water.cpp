/*
Category: Two Pointers
Approach:
Use two pointers at both ends and calculate area, moving the pointer with smaller height inward.
This ensures exploring maximum possible area efficiently.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size() - 1;
        int maxarea = 0;
        while(i<j){
            int l = min(height[i] , height[j]);
            int b = j - i;
            int area = l*b;
            maxarea = max(maxarea , area);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxarea;
    }
};