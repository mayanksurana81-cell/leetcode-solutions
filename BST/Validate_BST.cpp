/*
Category: Binary Search Tree / DFS
Approach:
Perform inorder traversal and keep track of previous node.
Since inorder of BST should be strictly increasing, if any violation occurs (current <= previous),
mark as invalid and stop traversal early.
Time Complexity: O(n)
Space Complexity: O(h)
Where h is height of tree due to recursion stack
*/
class Solution {
public:
    void inorder(TreeNode* root, TreeNode*& temp, bool& flag) {
        if (root == NULL || !flag) return;

        inorder(root->left, temp, flag);

        if (temp != NULL && root->val <= temp->val) {
            flag = false;
            return;
        }

        temp = root;

        inorder(root->right, temp, flag);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* temp = NULL;  // Keeps track of previous node
        bool flag = true;
        inorder(root, temp, flag);
        return flag;
    }
};