 /*
Category: Binary Tree, BFS, Ordered Maps

Approach:
- Perform a level-order traversal while tracking each node's:
  - Column index (horizontal position)
  - Row index (depth level)
- Store nodes in a nested ordered structure:
  - Outer map groups nodes by column.
  - Inner map groups nodes by row.
  - Multiset stores node values in sorted order when multiple nodes share the same row and column.
- During BFS:
  - Left child gets (col - 1, row + 1).
  - Right child gets (col + 1, row + 1).
- After traversal, iterate through columns from left to right and rows from top to bottom, collecting values into the final answer.

Time Complexity: O(n log n)
Space Complexity: O(n)
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){

            auto currPair = q.front();
            q.pop();

            TreeNode* curr = currPair.first;
            int col = currPair.second.first;
            int row = currPair.second.second;

            nodes[col][row].insert(curr->val);

            if(curr->left)
                q.push({curr->left,{col-1,row+1}});

            if(curr->right)
                q.push({curr->right,{col+1,row+1}});
        }

        vector<vector<int>> ans;

        for(auto &colPair : nodes){

            vector<int> colVals;

            for(auto &rowPair : colPair.second){

                colVals.insert(
                    colVals.end(),
                    rowPair.second.begin(),
                    rowPair.second.end()
                );
            }

            ans.push_back(colVals);
        }

        return ans;
    }
};
