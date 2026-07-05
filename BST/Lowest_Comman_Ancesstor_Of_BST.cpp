/*
Category: Binary Search Tree / Recursion
Approach:
Use BST property to find split point where one node lies in left subtree and other in right.
If both values are smaller, move left; if both are larger, move right; otherwise current node is LCA.
Time Complexity: O(h)
Space Complexity: O(h)
Where h is height of the tree due to recursion
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == NULL || root->val == p->val || root->val == q->val) return root;
        else if((root->val < max(p->val,q->val) && root->val > min(p->val,q->val))) return root;
        else if(root->val < p->val && root->val < q-> val) return lowestCommonAncestor(root->right , p , q);
        else return lowestCommonAncestor(root->left , p ,q);
    }
};
