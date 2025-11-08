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

using ull = unsigned long long;

class Solution {
public:
    void dfs(TreeNode* root, ull index, ull& maxIndex, ull& count) {
        if (!root) return;
        count++;
        maxIndex = max(maxIndex, index);
        dfs(root->left, 2 * index, maxIndex, count);
        dfs(root->right, 2 * index + 1, maxIndex, count);
    }

    bool isCompleteTree(TreeNode* root) {
        ull maxIndex = 1;
        ull count = 0;
        dfs(root, 1, maxIndex, count);
        return maxIndex == count;
    }

    // bool isCompleteTree(TreeNode* root) {
    //     if (!root) return true;

    //     queue<TreeNode*> q;
    //     q.push(root);
    //     bool lackNode = false;
    //     while (!q.empty()) {
    //         int sz = q.size();
    //         for (int i = 0; i < sz; i++) {
    //             TreeNode* node = q.front();
    //             q.pop();
    //             if (!node) {
    //                 lackNode = true;
    //                 continue;
    //             }

    //             if (lackNode) return false;
    //             q.push(node->left);
    //             q.push(node->right);
    //         }
    //     }
    //     return true;
    // }
};