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
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> dfs(int n) {
        vector<TreeNode*> current_permutations;

        auto it = memo.find(n);
        if (it != memo.end()) {
            return it->second;
        }

        if (n == 1) {
            TreeNode* root = new TreeNode(0);
            return memo[1] = { root };
        }

        for (int i = 1; i < n - 1; i += 2) {
            int left_count = i;
            int right_count = n - 1 - i;

            vector<TreeNode*> left_subtrees = dfs(left_count);
            vector<TreeNode*> right_subtrees = dfs(right_count);

            for (auto left: left_subtrees) {
                for (auto right: right_subtrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    current_permutations.push_back(root);
                }
            }
        }
        return memo[n] = current_permutations;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        return dfs(n);
    }
};