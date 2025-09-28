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
    // Approach: DFS traversal with backtracking
    // Time: O(n*n) in worst case (unbalanced)
    // Space: O(n) in worst case (unbalanced)

    void dfs(vector<vector<int>>& ans, vector<int>& path, TreeNode* root, int targetSum) {
        // choose
        targetSum -= root->val;
        path.push_back(root->val);

        // finish condition
        if (!root->left && !root->right) {
            if (targetSum == 0) {
                ans.push_back(path); // O(n) time
            }
        }

        // explore
        if (root->left) dfs(ans, path, root->left, targetSum);
        if (root->right) dfs(ans, path, root->right, targetSum);
        
        // unchoose
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};

        vector<vector<int>> ans;
        vector<int> path;
        dfs(ans, path, root, targetSum);
        return ans;
    }

    // Practice

    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    // }
};