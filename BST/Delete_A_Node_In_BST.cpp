/*
Category: Binary Search Tree / Recursion
Approach:
Search for the node to delete using BST property. Handle three cases:
leaf node (remove directly), one child (replace with child), two children (replace with inorder predecessor and delete it).
Recursively adjust tree to maintain BST structure.
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* iop(TreeNode* root){
    TreeNode* pred = root->left;
    while(pred->right!=NULL) pred = pred->right;
    return pred;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
    
    if(root->val == key){

        // case 1 : no child
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }

        // case 2 : 1 child
        if(root->left==NULL || root->right==NULL){
            if(root->left!=NULL) return root->left;
            else return root->right;

        }

        // case 3 : 2 child
        if(root->left!=NULL && root->right!=NULL) {
            root->val = iop(root)->val;
            root->left = deleteNode(root->left , root->val);
        }
    }
    else if(root->val > key){
        root->left = deleteNode(root->left , key);
    }

    else{
        root->right = deleteNode(root->right , key);

    }
    return root;
    }
};