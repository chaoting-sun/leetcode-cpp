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
    // Approach1: recursion
    // Time: O(n). n is the number of nodes. we have to traverse all nodes and flip their children in the tree
    // Space: O(h) = O(n). h is the height of the tree, which, in worst case, is O(n)

    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) return nullptr;
        
    //     TreeNode* tmp = root->left;
    //     root->left = root->right;
    //     root->right = tmp;

    //     invertTree(root->left);
    //     invertTree(root->right);
        
    //     return root;
    // }

    // Approach2: iteration
    // Time: O(n). Each node on the tree will be pushed and popped from queue one time
    // Space: O(n)

    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        return root;
    }
};