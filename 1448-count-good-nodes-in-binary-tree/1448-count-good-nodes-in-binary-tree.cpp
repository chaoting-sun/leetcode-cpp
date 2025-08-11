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
    // Time: O(n)
    // Space: O(n)
    
    // void recursion(TreeNode* root, int& count, int max_val) {
    //     // handle base case
    //     if (!root) return;

    //     // handle this node
    //     if (root->val >= max_val) {
    //         count++;
    //         max_val = root->val;
    //     }

    //     // go to other nodes
    //     recursion(root->left, count, max_val);
    //     recursion(root->right, count, max_val);
    // }

    // int goodNodes(TreeNode* root) {
    //     int count = 0;
    //     int max_val = INT_MIN;

    //     recursion(root, count, max_val);
    //     return count;
    // }

    // Approach2: iteration
    // Time: O(n)
    // Space: O(n)

    int goodNodes(TreeNode* root) {
        int count = 0;
        int max_val = INT_MIN;
        
        if (!root) return 0;
        
        queue<pair<TreeNode *, int>>q;
        q.push({ root, max_val });

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                int curr_max_val = q.front().second;
    
                q.pop();

                if (node->val >= curr_max_val) {
                    count++;
                }

                curr_max_val = max(curr_max_val, node->val);
                if (node->left) q.push({ node->left, curr_max_val });
                if (node->right) q.push({ node->right, curr_max_val });
            }
        }

        return count;
    }
};