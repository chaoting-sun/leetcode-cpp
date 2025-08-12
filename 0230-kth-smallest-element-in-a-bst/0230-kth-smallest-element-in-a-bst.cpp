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
    // recursion: inorder traversal
    // Time: O(H + k). inorder traversal go down to the left leaf before processing k nodes
    // Space: O(H). the call stack is with depth H.

    // void inorderTraversal(TreeNode* root, int &curr, int k, int &ans) {
    //     // base case
    //     if (!root) return;

    //     // go to the left node
    //     inorderTraversal(root->left, curr, k, ans);

    //     // handle the current node
    //     curr++;
    //     if (curr == k) {
    //         ans = root->val;
    //         return;
    //     } 

    //     // go to the right node
    //     inorderTraversal(root->right, curr, k, ans);
    // }

    // int kthSmallest(TreeNode* root, int k) {
    //     int ans = 0;
    //     int curr = 0;
    //     inorderTraversal(root, curr, k, ans);
    //     return ans;
    // }

    // iteration
    // Time: O(H + k). H is the tree height. Before starting popping out the node,
    // we have to go down to the tree leaf, which takes the tree height (H). for
    // balanced tree H = logn. for skewwed tree H = n
    // Space: O(H)

    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*> stk;
        int cnt = 0;

        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();

            cnt++;
            if (cnt == k) {
                return root->val;
            }
            root = root->right;
        }

        return -1;
    }
};