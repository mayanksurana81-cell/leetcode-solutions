/*
Category: Binary Tree / Recursion
Approach:
Compare both trees simultaneously. If both nodes are null, they are equal; if one is null or values differ, return false.
Recursively check left subtree and right subtree for structural and value equality.
Time Complexity: O(n)
Space Complexity: O(h)
Where h is height of tree due to recursion stack
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q==NULL) return true;
        if(p != NULL && q==NULL) return false;
        if(q!= NULL&& p==NULL) return false;
        if(p->val != q->val) return false;

        bool lst = isSameTree(p->left , q->left);
        if(lst==false) return false;
        
        bool rst = isSameTree(p->right , q->right);
        if(rst == false) return false;

        return true;

    }
};