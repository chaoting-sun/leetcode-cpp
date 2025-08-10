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
    // Approach1: Recursion
    // Time: O(n)
    // Space: O(n) in worst case (for complete unbalanced tree)

    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if (!p && !q) return true;

    //     if ((p && !q) || (!p && q)) return false;
    //     else if (p->val != q->val) return false;

    //     bool isLeftSame = isSameTree(p->left, q->left);
    //     bool isRightSame = isSameTree(p->right, q->right);
    //     return isLeftSame && isRightSame;
    // }

    // Approach2: Iteration
    // Time: O(n)
    // Space: O(n)

    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> nodes;

        nodes.push({ p, q });

        while (!nodes.empty()) {
            auto curr = nodes.front();
            nodes.pop();
            TreeNode* p_node = curr.first;
            TreeNode* q_node = curr.second;

            if (!p_node && !q_node) continue;
            if ((!p_node && q_node) || (p_node && !q_node)) return false;
            if (p_node->val != q_node->val) return false;

            nodes.push({ p_node->left, q_node->left });
            nodes.push({ p_node->right, q_node->right });
        }

        return true;
    }
};