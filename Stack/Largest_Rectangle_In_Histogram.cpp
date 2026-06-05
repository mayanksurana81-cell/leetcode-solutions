 /*
Category: Stack, Monotonic Stack

Approach:
- For each bar, find:
  - The index of the Previous Smaller Element (PSE) on the left.
  - The index of the Next Smaller Element (NSE) on the right.
- Use two monotonic increasing stacks to compute these boundaries.
- Once the boundaries are known:
  - The maximum width for a bar is:
    right[i] - left[i] - 1
  - The rectangle area using that bar as height is:
    height[i] × width
- Compute the area for every bar and return the maximum area obtained.

Time Complexity: O(n)
Space Complexity: O(n)
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st1 ,st2;
        int maxarea = 0;
        for(int i = 0; i<n ; i++){
            while(!st1.empty() && arr[st1.top()] >= arr[i]) st1.pop();
            if(st1.empty()){
                left[i] = -1;
            }else{
                left[i] = st1.top();
            }
            st1.push(i);
        }
        for(int i = n-1; i>= 0 ; i--){
            while(!st2.empty() && arr[st2.top()] >= arr[i]) st2.pop();
            if(st2.empty()){
                right[i] = n;
            }else{
                right[i] = st2.top();
            }
            st2.push(i);
        }
        for(int i = 0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int area = (width * arr[i]);
            maxarea = max(maxarea , area);
        }
        return maxarea;

    }
};