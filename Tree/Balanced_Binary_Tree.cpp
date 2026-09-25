/*
Category: Binary Tree, Recursion, Height Calculation

Approach:
- Recursively calculate the height of the left and right subtrees.
- If either subtree is already unbalanced, propagate -1 upward immediately.
- Compare the heights of both subtrees at each node; if their difference is greater than 1, return -1.
- Otherwise, return the current subtree height as max(left height, right height) + 1.
- The tree is balanced when the final returned value is not -1.

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
    int check(TreeNode* root){
        if(root == NULL) return 0;
        int lh = check(root->left);
        int rh = check(root->right);
        if(lh == -1 || rh == -1) return -1;
        if(abs(rh - lh) > 1) return -1;
        return max(lh,rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return check(root) != -1;
    }
};