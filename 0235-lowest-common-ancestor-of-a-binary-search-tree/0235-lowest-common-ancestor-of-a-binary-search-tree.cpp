/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Intuition: for the BST, if a node k is not the ancestor of the two distinct nodes p and q, then p and q should be either in the left subtree or right subtree
    // Approach: recursion
    // Time: O(n). the tree height
    // Space: O(n). the tree height

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (root->val > p->val && root->val > q->val) {
    //         return lowestCommonAncestor(root->left, p, q);
    //     } else if (root->val < p->val && root->val < q->val) {
    //         return lowestCommonAncestor(root->right, p, q);
    //     } else {
    //         return root;
    //     }
    // }

    // Approach: Iteration
    // Time: O(n)
    // Space: O(1)

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root->val > p->val && root->val > q->val) root = root->left;
            else if (root->val < p->val && root->val < q->val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};