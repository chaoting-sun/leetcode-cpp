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
    void flatten(TreeNode* root) {
        if (!root) return;
        if (!root->left) {
            flatten(root->right);
        } else {
            TreeNode *rightSubtree = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode *curr = root;
            while (curr->right) curr = curr->right;
            curr->right = rightSubtree;
            flatten(root->right);
        }
    }
};