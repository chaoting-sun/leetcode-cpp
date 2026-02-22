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

        pair<int,int> left_result = dfs(root->left);
        pair<int,int> right_result = dfs(root->right);

        int max_rob = root->val + left_result.second + right_result.second;
        int max_not_rob = max(left_result.first, left_result.second) + max(right_result.first, right_result.second);

        return { max_rob, max_not_rob };
    }

public:
    int rob(TreeNode* root) {
        pair<int,int> root_result = dfs(root);
        return max(root_result.first, root_result.second);
    }
};

// test case:
//      3
//    2   6
//     5    1
//  -> 11
// trace:
// dfs(root, false)
//  max_not_rob = dfs(2, false) + dfs(6, false)
//      dfs(2, false)
//          max_not_rob = dfs(null, false) + dfs(5, false)
//              dfs(null, false) = 0
//              dfs(5, false) = 5
//                  max_not_rob = dfs(null, false) + dfs(null, false)
//                  max_rob = 5 + dfs(null, false) + dfs(null, false) = 5
//              < 5
//          max_rob = 2 + dfs(null, true) + dfs(5, true)
//              dfs(null, false) = 0
//              < 2
//          < max(5, 2) = 5
//      dfs(6, false)
//          max_not_rob = dfs(null, false) + dfs(1, false)
//              dfs(null, false) = 0
//              dfs(1, false)
//                  max_not_rob = dfs(null, false) + dfs(null, false) = 0
//                  max_rob = 6 
//  max_rob = dfs(2, true) + dfs(6, true)