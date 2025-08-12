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
    // Approach1.1: Recursion (track upper bound and lower bound); Preorder Traversal
    // Time: O(n)
    // Space: O(n)

    // bool recursion(TreeNode* root, int lb, int ub, bool has_lb, bool has_ub) {
    //     // base case
    //     if (!root) return true;

    //     // check if the current node is valid
    //     if (has_lb && root->val <= lb) return false;
    //     if (has_ub && root->val >= ub) return false;

    //     // go to the left node
    //     int left_ub = min(root->val, ub);
    //     bool is_left_valid = recursion(root->left, lb, left_ub, has_lb, true);
        
    //     // go to the right node
    //     int right_lb = max(root->val, lb);
    //     bool is_right_valid = recursion(root->right, right_lb, ub, true, has_ub);

    //     return is_left_valid && is_right_valid;
    // }
    

    // bool isValidBST(TreeNode* root) {
    //     return recursion(root, INT_MIN, INT_MAX, false, false);
    // }

    // Recursion1.2: Recursion (track by node); Preorder Traversal
    // Time: O(n)
    // Space: O(n)

    // bool recursion(TreeNode* root, TreeNode* lb, TreeNode* ub) {
    //     // base case
    //     if (!root) return true;

    //     // check if the current node is valid
    //     if (lb && lb->val >= root->val) return false;
    //     if (ub && ub->val <= root->val) return false;

    //     // go to the left node
    //     bool is_left_valid = recursion(root->left, lb, root);
    //     // go to the right node
    //     bool is_right_valid = recursion(root->right, root, ub);

    //     return is_left_valid && is_right_valid;
    // }
    
    // bool isValidBST(TreeNode* root) {
    //     return recursion(root, nullptr, nullptr);
    // }

    // Recursion2: Recursion; inorder traversal
    // Time: O(n)
    // Space: O(n)

    // bool recursion(TreeNode* root, TreeNode* &prev) {
    //     if (!root) return true;

    //     // go to the left node
    //     if (!recursion(root->left, prev)) return false;

    //     // handle current node
    //     if (prev && prev->val >= root->val) return false;
    //     prev = root;

    //     // go to the right node
    //     if (!recursion(root->right, prev)) return false;

    //     return true;
    // }

    // bool isValidBST(TreeNode* root) {
    //     TreeNode* prev = nullptr;
    //     return recursion(root, prev);
    // }

    // Iteration
    // Time: O(n)
    // Space: O(n)

    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;

        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();

            if (prev && root->val <= prev->val) return false;
            prev = root;
            root = root->right;
        }

        return true;
    }
};