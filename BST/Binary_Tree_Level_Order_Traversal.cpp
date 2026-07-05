/*
Category: Binary Tree / DFS
Approach:
First compute height of tree to initialize result structure.
Then perform DFS traversal, passing level index and inserting each node into corresponding level vector.
Time Complexity: O(n)
Space Complexity: O(n)
Where recursion stack and result storage both take linear space
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
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));

    }
    void PushInOrder(TreeNode* root , vector<vector<int>> &ans , int level){
        if(root == NULL) return;
        ans[level].push_back(root->val);
        PushInOrder(root->left , ans , level + 1);
        PushInOrder(root->right , ans , level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int lvl = levels(root);
        for(int i = 1 ; i<=lvl ; i++){
            vector<int> v;
            ans.push_back(v);
        }

    PushInOrder(root , ans , 0);

        return ans;
    }
};
