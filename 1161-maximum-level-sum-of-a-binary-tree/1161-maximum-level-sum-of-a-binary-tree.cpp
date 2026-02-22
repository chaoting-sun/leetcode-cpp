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
    int maxLevelSum(TreeNode* root) {
        int min_level = 0, max_sum = INT_MIN;
        int curr_level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            curr_level++;
            int level_sum = 0;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (level_sum > max_sum) {
                min_level = curr_level;
                max_sum = level_sum;
            }
        }

        return min_level;
    }
};