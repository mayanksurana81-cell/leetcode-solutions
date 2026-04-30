/*
Category: Binary Search Tree / Recursion
Approach:
Traverse the tree and adjust child pointers to remove nodes outside [low, high].
For each node, fix left and right subtrees by skipping invalid nodes and recursively trimming valid subtrees.
A dummy node is used to handle cases where root itself gets trimmed.
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
    void Trim(TreeNode* root , int lo , int hi){
        if(root == NULL) return;
        while(root->left!=NULL){
            if(root->left->val < lo) root->left = root->left->right;
            else if(root->left->val > hi) root->left = root->left->left;
            else break;
        }
        while(root->right!=NULL){
            if(root->right->val > hi) root-> right = root->right->left;
            else if(root->right->val < lo) root-> right = root->right->right;
            else break;
        }
        Trim(root->left , lo , hi);
        Trim(root->right , lo , hi);

    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root->left == NULL & root->right == NULL){
            if(root-> val < low || root->val > high) return NULL;
            else return root;
        }
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        Trim(dummy , low , high);
        return dummy->left;
    }
};