/*
Category: Binary Tree / DFS
Approach:
Perform recursive postorder traversal by visiting left subtree, then right subtree,
and finally the current node, storing values in result vector.
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
void displayPOST(TreeNode* root ,vector<int>&ans){
    if(root == NULL) return;
   
    displayPOST(root->left,ans);
    displayPOST(root->right,ans);
     ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int>ans;
         displayPOST(root,ans);
         return ans;
    }
};
