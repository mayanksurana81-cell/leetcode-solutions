/*
Category: Binary Tree, BST, Inorder Traversal

Approach:
- Perform an inorder traversal of the BST, which visits values in sorted order.
- Keep track of the previously visited value and calculate the difference with the current node.
- Update the minimum difference after each consecutive pair of values.
- Use a boolean flag to handle the first visited node, since it has no previous value.

Time Complexity: O(n)
Space Complexity: O(h)
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
    void helper(TreeNode* root, int& prev, int& ans, bool& first){
        if(root == NULL) return;
        helper(root->left, prev, ans, first);
        if(!first){
        int dis = root->val - prev;
        ans = min(ans, (int)dis);
        }
        prev = root->val;
        first = false;
        helper(root->right, prev, ans, first);
    }
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;
        int prev = 0;
        int ans = INT_MAX;
        bool first = true;
        helper(root, prev, ans, first);
        return ans == INT_MAX ? 0 : ans;
    }
};