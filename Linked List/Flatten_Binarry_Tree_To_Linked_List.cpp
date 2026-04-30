/*
Category: Binary Tree / Iterative (Morris Traversal Style)
Approach:
Traverse the tree and for each node with a left child, attach its left subtree to the right
and connect the rightmost node of left subtree to the original right subtree.
Continue moving right and finally nullify all left pointers to get a flattened linked list.
Time Complexity: O(n)
Space Complexity: O(1)
Where transformation is done in-place without extra space
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left !=NULL){
                TreeNode* r = curr->right;
                curr->right = curr->left;
                TreeNode* pred = curr->left;
                while(pred->right !=NULL) pred = pred->right;
                pred->right = r;
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }

        }
        TreeNode* temp = root;
        while(temp->right !=NULL){
            temp->left = NULL;
            temp = temp->right;
        }


        
    }
};