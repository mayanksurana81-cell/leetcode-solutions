/*
Category: Binary Tree, Recursion, Divide and Conquer, Hash Map

Approach:
- Store the index of every value in the inorder traversal using a hash map for constant-time lookup.
- Use preorder to determine the root of each subtree, taking the current value and advancing pre_idx.
- Use the root's inorder position to divide the tree into left and right subtrees.
- Recursively construct the left subtree from the left inorder range and the right subtree from the right inorder range.

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
    TreeNode* helper(vector<int>& preorder, int &pre_idx, int left, int right, unordered_map<int,int>& mp){
        if(left > right) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_idx]);
        int in_idx = mp[preorder[pre_idx]];
        pre_idx++;
        root->left = helper(preorder, pre_idx, left, in_idx-1,mp);
        root->right = helper(preorder, pre_idx, in_idx+1, right,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_idx = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        return helper(preorder,pre_idx, 0, inorder.size()-1, mp);
    }
};