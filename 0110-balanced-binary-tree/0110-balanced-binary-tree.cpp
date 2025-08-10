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
    // Approach1: Top-down Recursion
    // check by the def. of balanced binary tree:
    // the difference between the heights of the two sub trees are not bigger than 1,
    // and both the left and right subtrees are the balanced binary tree.

    // Time: O(n^2) in worst case
    // 1. tree is skewwed: in the first level the node traverse O(n) nodes, the second level will be O(n-1) nodes,
    // so the time is O(n) + O(n-1) + ... + O(1) = O(n^2)
    // 2. tree is balanced: in the first level the node traverse O(n) nodes, the second level contain two nodes,
    // each traverse about n/2 nodes, so in total the time is still O(n). The height of a balanced tree is logn,
    // so the time is O(n*logn)

    // Space: O(n)

    // int depth(TreeNode* root) {
    //     if (!root) return 0;
    //     int left_depth = 1 + depth(root->left);
    //     int right_depth = 1 + depth(root->right);
    //     return max(left_depth, right_depth);
    // }

    // bool isBalanced(TreeNode* root) {
    //     if (!root) return true;
    //     // Check the current node (top)
    //     else if (abs(depth(root->left) - depth(root->right)) > 1) {
    //         return false;
    //     // Then check the children (down)
    //     } else {
    //         return isBalanced(root->left) && isBalanced(root->right);
    //     }
    // }

    // Approach2: Bottom-up Recursion (DFS)
    // Time: O(n). each node is processed once
    // Space: O(n). O(n) for skewwed tree, while O(logn) for balanced tree

    int height(TreeNode* root) {
        if (!root) return -1;
        
        int left_height = height(root->left);
        int right_height = height(root->right);

        if (abs(left_height - right_height) > 1) return -1;
        int curr_height = max(left_height, right_height) + 1;
        return curr_height;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int res = height(root);
        return res != -1 ? true : false;
    }
};