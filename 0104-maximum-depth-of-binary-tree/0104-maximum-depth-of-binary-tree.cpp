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
    // Approach: recursion. recursively traverse the current node, and its left and right node.
    // In each node, compute the left and right height respectively and return the maximum one.
    // Time: O(n). we need to traverse all nodes in the tree
    // Space: O(n). the tree in worst case has height = n

    int recursion(TreeNode* root, int h) {
        if (!root) return h;

        int left_h = 1 + recursion(root->left, h);
        int right_h = 1 + recursion(root->right, h);
        
        return max(left_h, right_h);
    }

    int maxDepth(TreeNode* root) {
        return recursion(root, 0);
    }

    // simplify

    // int maxDepth(TreeNode* root) {
    //     if (!root) return 0;

    //     int left_h = 1 + maxDepth(root);
    //     int right_h = 1 + maxDepth(root);
    //     return max(left_h, right_h);
    // }
};