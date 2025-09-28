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
    // Approach: DFS, Recursion
    // Time: O(n)
    // Space: O(h). h is the tree height

    void dfs(TreeNode* root, int pathSum, int& totalSum) {
        if (!root) return;

        pathSum = pathSum * 10 + root->val;
        if (!root->left && !root->right) {
            totalSum += pathSum;
            return;
        }

        dfs(root->left, pathSum, totalSum);
        dfs(root->right, pathSum, totalSum);
    }

    int sumNumbers(TreeNode* root) {
        int pathSum = 0, totalSum = 0;
        dfs(root, pathSum, totalSum);
        return totalSum;
    }

    // Practice

    int sumNumbers(TreeNode* root) {
        
    }    
};