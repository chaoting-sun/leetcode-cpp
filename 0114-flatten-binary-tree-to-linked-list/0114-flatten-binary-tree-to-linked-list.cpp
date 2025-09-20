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
    // Intuition: recursively traverse to the right subtree. for each current node, check if
    // it has left subtree. if the left subtree exists, move it to the right subtree, and connect
    // the original right subtree to the very right of the new right subtree.
    // Approach: Recursion

    // Time: O(n^2)
    // Space: O(n)

    // void flatten(TreeNode* root) {
    //     if (!root) return;
    //     if (!root->left) {
    //         flatten(root->right);
    //     } else {
    //         TreeNode *rightSubtree = root->right;
    //         root->right = root->left;
    //         root->left = nullptr;
    //         TreeNode *curr = root;
    //         while (curr->right) curr = curr->right;
    //         curr->right = rightSubtree;
    //         flatten(root->right);
    //     }
    // }

    // Time: O(n)
    // Space: O(n)

    TreeNode* flattenNode(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left && !root->right) return root;

        TreeNode* leftLast = flattenNode(root->left);
        TreeNode* rightLast = flattenNode(root->right);
        
        if (leftLast) {
            TreeNode* tempRightRoot = root->right;
            root->right = root->left;
            root->left = nullptr;
            leftLast->right = tempRightRoot;
        }

        return rightLast ? rightLast : leftLast;
    }

    void flatten(TreeNode* root) {
        flattenNode(root);
    }
};