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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            ans.push_back(q.front()->val);
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return ans;
    }

    // Approach: Recursion
    // Time: O(n)
    // Space: O(n). skewwed tree -> O(n), balanced tree -> O(logn)

    // void recursion(TreeNode* root, int level, vector<int> &ans) {
    //     // handle base case
    //     if (!root) return;
        
    //     // handle this node
    //     if (ans.size() < level) {
    //         ans.push_back(root->val);
    //     }

    //     // go to other nodes
    //     recursion(root->right, level+1, ans);
    //     recursion(root->left, level+1, ans);
    // }

    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> ans;
    //     recursion(root, 1, ans);
    //     return ans;
    // }

    // Approach: Iteration
    // Time: O(n)
    // Space: O(n). skewwed -> O(1), balanced tree -> O(n)

    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> ans;
    //     queue<TreeNode*> q;

    //     if (!root) return ans;
        
    //     q.push(root);
    //     while (!q.empty()) {
    //         int n = q.size();
    //         ans.push_back(q.front()->val);
    //         for (int i = 0; i < n; i++) {
    //             if (q.front()->right) q.push(q.front()->right);
    //             if (q.front()->left) q.push(q.front()->left);
    //             q.pop();
    //         }
    //     }

    //     return ans;
    // }
};