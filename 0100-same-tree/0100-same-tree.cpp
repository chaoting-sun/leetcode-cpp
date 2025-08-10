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
    // Approach: Recursion
    // Time: O(n)
    // Space: O(min(n,m)) in worst case. O(log(min(n,m)))

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;

        if ((p && !q) || (!p && q)) return false;
        else if (p->val != q->val) return false;

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);
        return isLeftSame && isRightSame;
    }
};