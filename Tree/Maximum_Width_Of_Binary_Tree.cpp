/*
Category: Binary Tree, BFS, Queue

Approach:
- Perform a level-order traversal while assigning each node an index based on its position in a complete binary tree.
- For every level, use the indices of the first and last nodes to calculate the width, including the gaps between nodes.
- The left child receives index 2 * index + 1 and the right child receives 2 * index + 2.
- Track the maximum width across all levels.

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int max_width = 0;
        while(!q.empty()){
            int level_size = q.size();
            unsigned long long st_idx = q.front().second;
            unsigned long long end_idx = q.back().second;
            max_width = max(max_width, (int)(end_idx - st_idx + 1));
            for(int i = 0; i < level_size; i++){
                auto curr = q.front();
                q.pop();
                if(curr.first->left){
                    q.push({curr.first->left, 2*curr.second+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right, 2*curr.second+2});
                }
            }
        }
        return max_width;
    }
};