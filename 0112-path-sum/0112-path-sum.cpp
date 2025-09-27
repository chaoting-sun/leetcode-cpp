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
    bool dfs(TreeNode* root, int leftSum) {
        leftSum -= root->val;

        // if the current node is a leaf and the leftSum == 0 -> true
        if (!root->left && !root->right) {
            return leftSum == 0;
        }

        bool result = false;
        if (root->left) result |= dfs(root->left, leftSum);
        if (root->right) result |= dfs(root->right, leftSum);
        return result;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, targetSum);
    }
};