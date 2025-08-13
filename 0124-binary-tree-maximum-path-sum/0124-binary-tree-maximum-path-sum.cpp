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
    int max_sum;

    int recursion(TreeNode* root) {
        if (!root) return 0;

        int left_len = recursion(root->left);
        int right_len = recursion(root->right);

        int l_sum = left_len + root->val;
        int c_sum = root->val;
        int r_sum = right_len + root->val;
        int lcr_sum = left_len + root->val + right_len;

        int root_max_sum = max(lcr_sum, max(c_sum, max(l_sum, r_sum)));

        max_sum = max(max_sum, root_max_sum);
        return max(c_sum, max(l_sum, r_sum));
    }

    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        recursion(root);
        return max_sum;
    }
};