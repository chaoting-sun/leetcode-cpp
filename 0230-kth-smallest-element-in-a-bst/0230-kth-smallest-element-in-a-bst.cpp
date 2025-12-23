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
private:
    void inorderTraversal(TreeNode* root, int k, int& count, int& kth_val) {
        if (!root) return;

        inorderTraversal(root->left, k, count, kth_val);
        
        count++;
        if (count == k) {
            kth_val = root->val;
            return;
        }

        inorderTraversal(root->right, k, count, kth_val);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int kth_val = -1;
        int count = 0;
        inorderTraversal(root, k, count, kth_val);
        return kth_val;
    }
};

// Submit Error
// CE: address of overloaded function 'count' does not match required type 'int'
// Reason: does not define count before passing it into inorderTraversal