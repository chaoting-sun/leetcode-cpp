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
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        // base case
        if (!root && !subRoot) return true;
        if ((!root && subRoot) || (root && !subRoot)) return false;
        
        // check if the current node is the same
        if (root->val != subRoot->val) return false;
        // check if both the left and right subtree is the same
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* &subRoot) {
        if (!root) return false;

        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};