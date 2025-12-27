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
// class Solution {
// private:
//     bool isValid(TreeNode* root, long long left_bound, long long right_bound) {
//         if (!root) return true;

//         long long current_val = root->val;
//         if (current_val <= left_bound || current_val >= right_bound) {
//             return false;
//         }
        
//         bool is_left_valid = isValid(root->left, left_bound, current_val);
//         bool is_right_valid = isValid(root->right, current_val, right_bound);
//         return is_left_valid && is_right_valid;
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         long long left_bound = LLONG_MIN;
//         long long right_bound = LLONG_MAX;
//         return isValid(root, left_bound, right_bound);
//     }
// };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        stack<TreeNode*> stk;
        long long curr_max = LLONG_MIN;
        TreeNode* curr = root;

        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            if ((long long)curr->val <= curr_max) {
                return false;
            }
            curr_max = (long long)curr->val;

            curr = curr->right;
        }

        return true;
    }
};

// Submit Error
// -1e+31 is outside the range of representable values of type 'long long'
// to
// long long left_bound = LLONG_MIN;