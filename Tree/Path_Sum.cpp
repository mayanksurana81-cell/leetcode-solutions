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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) return root->val == target;
        return hasPathSum(root->left , target - root->val) || hasPathSum(root->right , target - root->val);
    }
};