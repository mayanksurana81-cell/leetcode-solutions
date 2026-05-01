/*
Category: Binary Search Tree / DFS
Approach:
Perform reverse inorder traversal (right → root → left) to process nodes in descending order.
Maintain a running sum and update each node’s value to include sum of all greater nodes.
Time Complexity: O(n)
Space Complexity: O(h)
Where h is height of tree due to recursion stack
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
    void helper(TreeNode* root , int &sum){
        
        if(root == NULL) return;
        helper(root->right , sum);
        root->val = sum + root->val;
        sum = root->val;
        helper(root->left , sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        helper(root , sum);
        return root;
    }
};