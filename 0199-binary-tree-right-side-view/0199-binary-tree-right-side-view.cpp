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
    void recursion(TreeNode* root, int level, vector<int> &ans) {
        // handle base case
        if (!root) return;
        
        // handle this node
        if (ans.size() < level) {
            ans.push_back(root->val);
        }

        // go to other nodes
        recursion(root->right, level+1, ans);
        recursion(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursion(root, 1, ans);
        return ans;
    }
};