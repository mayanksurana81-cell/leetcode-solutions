/*
Category: Binary Tree / Morris Traversal
Approach:
Perform inorder traversal without recursion or stack by temporarily creating threads to predecessor nodes.
For each node, link its inorder predecessor to itself, traverse left, then restore the tree and move right.
Time Complexity: O(n)
Space Complexity: O(1)
Where traversal is done in-place without extra stack or recursion
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left != NULL){
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){ // link
                    pred->right = curr;
                    curr = curr->left;
                }
                else{ // pred->right == curr; // unlink
                        pred->right = NULL;
                        ans.push_back(curr->val);
                        curr = curr->right;
                }

            }
            else{ // curr->left == NULL
                    ans.push_back(curr->val);
                    curr = curr->right;
            }
        }


        return ans;
    }
};