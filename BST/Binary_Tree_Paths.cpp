/*
Category: Binary Tree / DFS
Approach:
Perform DFS traversal while building a path string from root to leaf.
At each node, append current value to path string and add "->" when moving deeper.
When a leaf node is reached, store the complete path in result.
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
void helper(TreeNode* root , string s , vector<string> &ans ){
    if(root == NULL) return;
    string a = to_string(root->val);
    if(root->left == NULL && root -> right == NULL){
        s += a;
        ans.push_back(s);
    }
    helper(root->left , s+a+"->" , ans);
    helper(root->right , s+a+"->" , ans);


}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root , "" , ans);
        return ans;
    }
};