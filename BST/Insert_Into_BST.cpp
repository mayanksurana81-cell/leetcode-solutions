/*
Category: Binary Search Tree / Recursion
Approach:
Traverse the tree using BST property and insert the new node at correct position.
Move left if value is smaller, right if larger, and attach node when null position is found.
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
    void insert(TreeNode* root , TreeNode* temp){
        if(root == NULL) return;
        else if(root->val > temp->val){
             if(root->left == NULL){
                 root->left = temp;
                    return;
             }
             insert(root->left , temp);
        }
        else {
            if(root->right == NULL) {
                root->right = temp;
                    return;
            }
            insert(root->right , temp);}
            
    }
    TreeNode* insertIntoBST(TreeNode* root, int value) {
        TreeNode* temp = new TreeNode(value);
        if(root == NULL) return temp;
        insert(root,temp);
        return root;
    }
};