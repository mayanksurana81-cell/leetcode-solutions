 /*
Category: Binary Search Tree, Divide and Conquer

Approach:
- Perform an inorder traversal of the BST and store the node pointers in a vector.
- Since inorder traversal of a BST produces nodes in sorted order,
  the vector represents the sorted sequence of tree nodes.
- Recursively build a balanced BST:
  - Choose the middle node as the root.
  - Build the left subtree from the left half of the vector.
  - Build the right subtree from the right half of the vector.
- Reusing the middle element at every step ensures the resulting BST is height-balanced.

Time Complexity: O(n)
Space Complexity: O(n)
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
    void store(vector<TreeNode*> &values, TreeNode* root){
        if(root == nullptr) return;
        store(values, root->left);
        values.push_back(root);
        store(values, root->right);
    }
    TreeNode* Bsearch(vector<TreeNode*> &values, int low, int high){
        if(low > high) return nullptr;
        int mid = low + (high - low) /2;
        values[mid]->left = Bsearch(values, low, mid - 1);
        values[mid]->right = Bsearch(values, mid + 1, high);
        return values[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> values;
        store(values,root);
       return Bsearch(values, 0, values.size()-1);
    }
};