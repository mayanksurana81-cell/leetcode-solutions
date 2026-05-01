/*
Category: Binary Search Tree
Approach:
Construct BST by inserting each element from preorder into the tree using BST insertion rules.
Start with first element as root and iteratively insert remaining elements in correct position.
Time Complexity: O(n^2)
Space Complexity: O(h)
Where h is height of tree (worst case n for skewed tree)
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
    void insert(TreeNode* root , int val){
         if(root->val > val){
            if(root->left == NULL) {
                root->left = new TreeNode(val);
                return;
            }
            else insert(root->left , val);
        }
        else{
            if(root->right == NULL) {
                root->right = new TreeNode(val);
                return ;
            }
            else insert(root->right , val);

        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1 ; i<preorder.size() ; i++){
            insert(root , preorder[i]);
        }
        return root;
    }
};