/*
Category: Binary Tree, DFS, Recursion

Approach:
- Traverse the main tree recursively and check every node as a possible starting point of the subtree.
- When the current node has the same value as the subtree root, use isIdentical() to recursively compare both trees.
- isIdentical() checks corresponding left and right subtrees along with node values.
- If no matching subtree is found at the current node, recursively search its left and right subtrees.

Time Complexity: O(n × m)
Space Complexity: O(n + m)
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
    bool isIdentical(TreeNode* p, TreeNode* q){
        if(!p || !q) return p==q;
        bool is_left_same = isIdentical(p->left, q->left);
        bool is_right_same = isIdentical(p->right, q->right);
        return is_left_same && is_right_same && p->val == q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return root == subRoot;
        if(root->val == subRoot->val && isIdentical(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};