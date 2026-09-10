/*
Category: Binary Tree, DFS, Recursion, Postorder Traversal

Approach:
- Recursively calculate the sum and number of nodes in each subtree.
- For every node, combine the sum and node count from its left and right subtrees with the current node.
- Calculate the integer average of the current subtree.
- If the average equals the current node's value, increment the answer.
- Return the subtree's total sum and node count to its parent.

Time Complexity: O(n)
Space Complexity: O(h)
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
int ans = 0;
    pair<int,int> helper(TreeNode* root){
        if(root == NULL) return {0,0};
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        int sum = left.first + right.first + root->val;
        int node_count = left.second + right.second + 1;
        int avg = sum / node_count;
        if(avg == root->val) ans++;
        return {sum, node_count};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};