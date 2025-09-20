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

    // Intuition: To flatten the tree, we can firstly flatten the left subtree and right subtree,
    // and then flatten the current subtree. to flatten from the current node, move the left subtree
    // to the right subtree and connect the right subtree to the new right subtree's right node.
    // To do this, we have to get the last node of the flattened left/right subtree, so in base case,
    // if a node has no left and right node, return itself, if one of which exists, then flatten, and
    // return the last node.
    // Approach: Divide and Conquer

    // Time: O(n)
    // Space: O(n)

    // TreeNode* flattenTree(TreeNode* root) {
    //     if (!root) return nullptr;
    //     if (!root->left && !root->right) return root;

    //     TreeNode* leftLast = flattenTree(root->left);
    //     TreeNode* rightLast = flattenTree(root->right);
        
    //     if (leftLast) {
    //         TreeNode* tempRightRoot = root->right;
    //         root->right = root->left;
    //         root->left = nullptr;
    //         leftLast->right = tempRightRoot;
    //     }

    //     return rightLast ? rightLast : leftLast;
    // }

    // void flatten(TreeNode* root) {
    //     flattenTree(root);
    // }

    // Intuition: start from root and traverse downward. push the right node and then right node, and then
    // connect the current node's right node to the stack pop and set its left node to null. so that for
    // each node we move the head of its left subtree to its right.

    // Approach: Stack
    // Time: O(n)
    // Space: O(n)

    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
            if (!stk.empty()) node->right = stk.top();
            node->left = nullptr;
        }
    }
};