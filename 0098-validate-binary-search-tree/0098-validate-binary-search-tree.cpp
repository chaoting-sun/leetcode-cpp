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
    bool recursion(TreeNode* root, int lb, int ub, bool has_lb, bool has_ub) {
        // base case
        if (!root) return true;

        // check if the current node is valid
        if (has_lb && root->val <= lb) return false;
        if (has_ub && root->val >= ub) return false;

        // go to the left node
        int left_ub = min(root->val, ub);
        bool is_left_valid = recursion(root->left, lb, left_ub, has_lb, true);
        
        // go to the right node
        int right_lb = max(root->val, lb);
        bool is_right_valid = recursion(root->right, right_lb, ub, true, has_ub);

        return is_left_valid && is_right_valid;
    }
    

    bool isValidBST(TreeNode* root) {
        return recursion(root, INT_MIN, INT_MAX, false, false);
    }
};