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

// Approach: DFS
// Time: O(n). we visited each node exactly once
// Space: O(n). in worst case the tree is unbalanced.

class Solution {
public:
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if (!root) return false;

    //     targetSum -= root->val;
    //     if (!root->left && !root->right) {
    //         return targetSum == 0;
    //     }
    //     return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    // }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        stack<pair<TreeNode*, int>> nodes;
        nodes.push({ root, targetSum });

        while (!nodes.empty()) {
            auto [currNode, currSum] = nodes.top();
            nodes.pop();

            currSum -= currNode->val;

            if (!currNode->left && !currNode->right && currSum == 0) {
                return true;
            }
            if (currNode->left) {
                nodes.push({ currNode->left, currSum });
            }
            if (currNode->right) {
                nodes.push({ currNode->right, currSum });
            }
        }

        return false;
    }
};