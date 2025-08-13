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
    // Approach: Recursion. DFS and constantly compute the max path. we only compute the path
    // under the current node, which includes:
    // - c: itself
    // - lc: left + itself
    // - rc: right + itself
    // - lrc: left + itself + right
    // the recursion function will return the maximum sum with path ends with the current node
    // to avoid split
    
    // Time: O(n)
    // Space: O(n)

    // int max_sum;

    // int gainFromSubtree(TreeNode* root) {
    //     if (!root) return 0;

    //     int _l_sum = recursion(root->left);
    //     int _r_sum = recursion(root->right);

    //     int l_sum = _l_sum + root->val;
    //     int c_sum = root->val;
    //     int r_sum = _r_sum + root->val;
    //     int lcr_sum = _l_sum + root->val + _r_sum;

    //     int root_max_sum = max(lcr_sum, max(c_sum, max(l_sum, r_sum)));

    //     max_sum = max(max_sum, root_max_sum);
    //     return max(c_sum, max(l_sum, r_sum));
    // }

    // int maxPathSum(TreeNode* root) {
    //     max_sum = INT_MIN;
    //     gainFromSubtree(root);
    //     return max_sum;
    // }

    // simplify

    int max_sum;

    int gainFromSubtree(TreeNode* root) {
        if (!root) return 0;

        int l_sum = gainFromSubtree(root->left);
        int r_sum = gainFromSubtree(root->right);

        l_sum = max(l_sum, 0);
        r_sum = max(r_sum, 0);
        max_sum = max(max_sum, l_sum + root->val + r_sum);

        return max(l_sum, r_sum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        gainFromSubtree(root);
        return max_sum;
    }
};