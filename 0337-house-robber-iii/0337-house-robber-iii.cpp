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
    unordered_map<TreeNode*, int> memo_rob, memo_not_rob;

    int dfs(TreeNode* root, bool is_parent_robbed) {
        if (!root) return 0;
    
        int max_not_rob = 0, max_rob = 0;
        
        // not rob the node
        auto it_not_rob = memo_not_rob.find(root);
        if (it_not_rob != memo_not_rob.end()) {
            max_not_rob = it_not_rob->second;
        } else {
            max_not_rob += dfs(root->left, false);
            max_not_rob += dfs(root->right, false);
            memo_not_rob[root] = max_not_rob;
        }

        if (is_parent_robbed) return max_not_rob;

        // rob the node
        auto it_rob = memo_rob.find(root);
        if (it_rob != memo_rob.end()) {
            max_rob = it_rob->second;
        } else {
            max_rob = root->val;
            max_rob += dfs(root->left, true);
            max_rob += dfs(root->right, true);
            memo_rob[root] = max_rob;
        }

        return max(max_rob, max_not_rob);
    }

public:
    int rob(TreeNode* root) {
        return dfs(root, false);
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