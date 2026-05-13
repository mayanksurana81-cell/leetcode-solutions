/*
Category: Binary Search Tree / Recursion
Approach:
Use BST property to search for the value by recursively moving left if target is smaller
or right if target is larger, until node is found or null is reached.
Time Complexity: O(h)
Space Complexity: O(h)
Where h is height of tree due to recursion
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val) return root;
        else if(root->val > val) return searchBST(root->left , val);
        else return searchBST(root->right , val);
    }
};
