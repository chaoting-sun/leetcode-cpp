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
    unordered_map<TreeNode*, pair<int, int>> memo; // rob, not rob

    pair<int,int> dfs(TreeNode* root) {
        if (!root) return { 0, 0 };

        auto [l_rob, l_skip] = dfs(root->left);
        auto [r_rob, r_skip] = dfs(root->right);

        int rob = root->val + l_skip + r_skip;
        int skip = max(l_rob, l_skip) + max(r_rob, r_skip);

        return { rob, skip };
    }

public:
    int rob(TreeNode* root) {
        auto [root_rob, root_skip] = dfs(root);
        return max(root_rob, root_skip);
    }
};

// run it in post order
// test case:
//      3
//    2   6
//     5    1
//  -> 11
// trace:
// - node 5
//  l_rob, l_skip = 0, 0
//  r_rob, r_skip = 0, 0
//  rob = 5
//  skip = 0
//  < [5, 0]
// - node 1
//  < [1, 0]
// - node 2
//  l_rob, l_skip = dfs(null) = 0, 0
//  r_rob, r_skip = dfs(5) = 5, 0
//  rob = 2
//  skip = 0 + 5 = 5
//  < [2, 5]
// - node 6
//  l_rob, l_skip = dfs(null) = 0, 0
//  r_rob, r_skip = dfs(1) = 1, 0
//  rob = 6
//  skip = 1
//  < [6, 1]
// - node 3
//  l_rob, l_skip = dfs(2) = 2, 5
//  r_rob, r_skip = dfs(6) = 6, 1
//  rob = 3 + 5 + 1 = 9
//  skip = 5 + 6 = 11