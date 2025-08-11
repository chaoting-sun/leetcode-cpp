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
    // Approach: Preorder traversal
    // Time: O(n)
    // Space: O(tree height + # nodes) <= O(2n) = O(n)

    void recursion(TreeNode* root, int level, vector<vector<int>> &ans) {
        if (!root) return;
        if (ans.size() < level + 1) {
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        recursion(root->left, level + 1, ans);
        recursion(root->right, level + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        recursion(root, 0, ans);
        return ans;
    }
};