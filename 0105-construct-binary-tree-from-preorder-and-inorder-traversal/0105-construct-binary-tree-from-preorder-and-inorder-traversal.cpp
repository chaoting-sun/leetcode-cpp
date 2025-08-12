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
    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
        // base case
        if (pre_l > pre_r) return nullptr;
        
        // the root between the subtree
        int curr_val = preorder[pre_l];
        
        // sequentially find the position of the root
        int pos = in_l;
        while (pos <= in_r) {
            if (curr_val == inorder[pos]) break;
            pos++;
        }

        TreeNode* node = new TreeNode(curr_val);

        int n_left = pos - in_l; // # nodes that is at the left of pos in inorder
        int n_right = in_r - pos; // # nodes that is at the right of pos in inorder

        node->left = recursion(preorder, inorder, pre_l + 1, pre_l + n_left, in_l, pos - 1);
        node->right = recursion(preorder, inorder, pre_l + 1 + n_left, pre_r, pos + 1, in_r);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return recursion(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};