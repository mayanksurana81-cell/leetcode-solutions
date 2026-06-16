 /*
Category: Binary Search Tree, Ordered Set

Approach:
- Traverse the array from right to left.
- Maintain an ordered set containing values of the form 2 * nums[j]
  for all elements to the right of the current index.
- For each nums[i]:
  - Count how many stored values are strictly less than nums[i].
  - Every such value corresponds to a valid reverse pair satisfying:
      nums[i] > 2 * nums[j]
  - Add this count to the answer.
- Insert 2 * nums[i] into the ordered set for future elements.
- Using order_of_key() allows counting qualifying elements in O(log n).

Time Complexity: O(n log n)
Space Complexity: O(n)
 */
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define oset tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        oset os;
        int ans = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            ans += os.order_of_key(nums[i]);
            os.insert(2LL *nums[i]);
        }
        return ans;
    }
};