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
    // Approach: Recursion
    // Time: O(n)
    // Space: O(n) in worst case.
    
    int recursion(TreeNode* root, int &max_nodes) {
        if (!root) return 0;

        int left_max_nodes = recursion(root->left, max_nodes);
        int right_max_nodes = recursion(root->right, max_nodes);
        int curr_nodes = left_max_nodes + 1 + right_max_nodes;
        max_nodes = max(max_nodes, curr_nodes);
        
        return max(left_max_nodes, right_max_nodes) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_nodes = 0;
        recursion(root, max_nodes);
        return max_nodes - 1;
    }
};