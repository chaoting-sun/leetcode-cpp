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
    void recursion(TreeNode* root, int level, int &max_level, unordered_map<int, vector<int>> &level2nodes) {
        if (!root) return;
        
        level2nodes[level].push_back(root->val);
        max_level = max(max_level, level + 1);

        recursion(root->left, level + 1, max_level, level2nodes);
        recursion(root->right, level + 1, max_level, level2nodes);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_map<int, vector<int>> level2nodes;
        int level = 0, max_level = 0;
        recursion(root, level, max_level, level2nodes);

        vector<vector<int>> ans(max_level);
        for (int i = 0; i < max_level; i++) {
            ans[i] = level2nodes[i];
        }
        return ans;
    }
};