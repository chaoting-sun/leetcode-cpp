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
    // Approach1: recursion. recursively traverse the current node, and its left and right node.
    // In each node, compute the left and right height respectively and return the maximum one.
    // Time: O(n). we need to traverse all nodes in the tree
    // Space: O(n). the tree in worst case has height = n

    // int recursion(TreeNode* root, int h) {
    //     if (!root) return h;

    //     int left_h = 1 + recursion(root->left, h);
    //     int right_h = 1 + recursion(root->right, h);
        
    //     return max(left_h, right_h);
    // }

    // int maxDepth(TreeNode* root) {
    //     return recursion(root, 0);
    // }


    // simplify the code

    // int maxDepth(TreeNode* root) {
    //     if (!root) return 0;

    //     int left_h = 1 + maxDepth(root->left);
    //     int right_h = 1 + maxDepth(root->right);
    //     return max(left_h, right_h);
    // }

    // Approach2: Iteration by BFS
    // Time: O(n). we need to traverse all nodes
    // Space: O(n). in worst case, the tree is a complete binary tree. There will be n/2 nodes at the last level.
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int h = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            h++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return h;
    }  
};