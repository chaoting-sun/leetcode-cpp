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
    // recursion
    // time: O(n). n = # nodes
    // space: O(n) in worst case; O(logn) in average case

    // void inorder(TreeNode* root, vector<int>& ans) {
    //     if (!root) return;
    //     inorder(root->left, ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     inorder(root, ans);
    //     return ans;
    // }

    // stack
    // time: O(n)
    // space: O(n)

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        
        if (!root) return {};
        TreeNode *curr = root;

        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }  
};