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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        deque<TreeNode*> q;
        q.push_back(root);

        bool inOrder = true;
        while (!q.empty()) {
            int size = q.size();
            ans.push_back({});

            if (inOrder) {
                for (int i = 0; i < size; i++) {
                    TreeNode* next = q.back();
                    q.pop_back();
                    ans[ans.size() - 1].push_back(next->val);
                    if (next->left) q.push_front(next->left);
                    if (next->right) q.push_front(next->right);
                }
            } else {
                for (int i = 0; i < size; i++) {
                    TreeNode* next = q.front();
                    q.pop_front();
                    ans[ans.size() - 1].push_back(next->val);
                    if (next->right) q.push_back(next->right);
                    if (next->left) q.push_back(next->left);
                }
            }
            inOrder = !inOrder;
        }
        return ans;
    }
};

//    3
//   9 20
// 2 4 15 7

// 3 -> 20 9 -> 2 4 15 7

// [3]
// pop back, l->r, push front
// [20 9]
// pop front, r->l, push back
// [7 15 4 2]
// pop back, l-> r, push front