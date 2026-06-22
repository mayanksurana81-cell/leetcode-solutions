/*
Category: Binary Search Tree / Divide and Conquer
Approach:
Pick the middle element as root to maintain balance, then recursively build left subtree
from left half and right subtree from right half of the array.
This ensures height-balanced BST construction.
Time Complexity: O(n)
Space Complexity: O(log n)
Where recursion depth corresponds to height of balanced tree
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
TreeNode* helper(vector<int>& nums , int lo , int hi){
    if(lo>hi) return NULL;
    int mid = lo + (hi-lo)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums , lo , mid-1);
    root->right = helper(nums , mid+1 , hi);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums , 0 , n-1);
    }
};
