/*
Category: Binary Tree / DFS
Approach:
Perform recursive preorder traversal by visiting current node first,
then recursively traversing left subtree followed by right subtree.
Store visited values in result vector.
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
void displayPre(TreeNode* root , vector<int>&ans){
    if(root == NULL) return;
    ans.push_back(root->val);
    displayPre(root->left,ans);
    displayPre(root->right,ans);
}
    vector<int> preorderTraversal(TreeNode* root) {
        //if(root == NULL) return NULL;
         vector<int> ans;
         displayPre(root,ans);
        return ans;
    }
};
