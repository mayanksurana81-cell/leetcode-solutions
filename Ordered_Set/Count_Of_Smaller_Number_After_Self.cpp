 /*
Category: Binary Search Tree, Ordered Set

Approach:
- Traverse the array from right to left.
- Maintain an ordered set containing all elements seen so far to the right.
- For each element:
  - Insert it into the ordered set.
  - Use order_of_key(nums[i]) to count how many elements in the set are strictly smaller than it.
- Store this count as the answer for the current index.
- Processing from right to left ensures the ordered set always represents the elements appearing after the current position.

Time Complexity: O(n log n)
Space Complexity: O(n)
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset os;
        for(int i = nums.size() - 1; i>= 0; i--){
            os.insert(nums[i]);
            nums[i] = os.order_of_key(nums[i]);
        }
        return nums;
    }
};