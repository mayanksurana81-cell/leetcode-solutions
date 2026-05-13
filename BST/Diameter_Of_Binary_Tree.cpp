/*
Category: Binary Tree / DFS
Approach:
For every node, compute height of left and right subtrees and use their sum as diameter passing through that node.
Recursively evaluate all nodes while maintaining the maximum diameter found globally.
Time Complexity: O(n^2);
Space Complexity: O(h);
Where h is height of tree due to recursion stack and heights are recomputed repeatedly
*/

class Solution {
public:
int maxDia = 0;
int levels(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia =  levels(root->left) + levels(root->right);
        maxDia = max(dia,maxDia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxDia;

    }
};
