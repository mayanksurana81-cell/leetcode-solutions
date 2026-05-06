/*
Category: Binary Tree / Recursion
Approach:
Check whether nodes p and q exist in left or right subtree using a helper function.
If they lie in different subtrees of current node, then current node is LCA.
Otherwise recursively move to the subtree where both nodes exist.
Time Complexity: O(n^2)
Space Complexity: O(h)
Where h is height of tree due to recursion stack and repeated subtree searches
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
bool ExistInTree(TreeNode* root , TreeNode* target){
    if(root == NULL) return false;
    if(root == target) return true;
    return ExistInTree(root->left , target) || ExistInTree(root->right , target);
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        else if(ExistInTree(root->left , p) && ExistInTree(root->right , q) ) return root;
        else if(!ExistInTree(root->left , p) && !ExistInTree(root->right , q) ) return root;
        else if(ExistInTree(root->left , p) && !ExistInTree(root->right , q) ) return lowestCommonAncestor(root->left , p , q); 
        else return lowestCommonAncestor(root->right , p , q);
    }
};