/*
Category: Binary Tree, Recursion

Approach:
- Recursively compare the left and right subtrees as mirror images.
- For each pair of nodes, first check whether both are null or only one is null.
- If both exist, compare their values and then compare the left child of one with the right child of the other, and vice versa.
- The tree is symmetric only when all corresponding mirror nodes satisfy these conditions.

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
    bool helper(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        if(left->val != right->val) return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left , root->right);
    }
};