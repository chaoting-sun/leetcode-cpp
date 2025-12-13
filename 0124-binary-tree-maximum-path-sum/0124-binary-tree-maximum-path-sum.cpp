// N range: [1, 3*10^4]
// Value range: -1000 <= val <= 1000

// for each node, optimal path includes
// 1. node
// 2. node + max(0, max sum that ends with node->left) + max(0, max sum that ends with node->right)

// bottom up approach -> post-order traversal (dfs)
// function
//  - max_left_sum = getMaxSum(node->left) // ends with node->left
//  - max_right_sum = getMaxSum(node->right) // ends with node->right
//  - max_sum = max(max_sum, node->val + max(max_left_sum, 0), max(max_right_sum, 0))
//  > return node->val + max(max(max_left_sum, 0) max(max_right_sum, 0))

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
    int getMaxPathSum(TreeNode* root, int& maxSum) {
        int max_left_sum = getMaxPathSum(root->left, maxSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        getMaxPathSum(root, maxSum);
    }
};