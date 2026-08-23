/*
Category: Binary Tree, BFS, Queue, Heap, Priority Queue

Approach:
- Perform a level-order traversal using BFS and use a NULL marker to identify the end of each level.
- Calculate the sum of nodes at every level and maintain a min-heap containing only the k largest level sums.
- Whenever the heap size exceeds k, remove the smallest sum.
- After processing all levels, the top of the min-heap is the kth largest level sum.
- Return -1 if the tree contains fewer than k levels.

Time Complexity: O(n log k)
Space Complexity: O(n + k)
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        long long sum = 0;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL && !q.empty()){
                pq.push(sum);
                if(pq.size() > k)pq.pop();
                sum = 0;
                q.push(NULL);
                continue;
            }
            if(curr == NULL && q.empty()) break;
            sum += curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        pq.push(sum);
        if(pq.size() > k) pq.pop();
        return pq.size() != k ? -1 :  pq.top();
    }
};