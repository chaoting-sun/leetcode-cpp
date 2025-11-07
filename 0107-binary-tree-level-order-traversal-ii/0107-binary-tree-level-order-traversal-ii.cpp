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
    void preorder(TreeNode* root, int level, vector<vector<int>>& ans) {
        if (!root) return;

        if (ans.size() < level + 1) ans.push_back({});
        ans[level].push_back(root->val);
        if (root->left) preorder(root->left, level + 1, ans);
        if (root->right) preorder(root->right, level + 1, ans);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        preorder(root, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};