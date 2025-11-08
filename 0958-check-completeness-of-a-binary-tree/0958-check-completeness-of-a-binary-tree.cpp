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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool lackNode = false;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (!node) {
                    lackNode = true;
                    continue;
                }

                if (lackNode) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

// [1,2,3,4,5,6,7,8,9,10,11,12,13,null,null,15]

//             1
//            2 3
//           4 5 6
//          7 8 9 10
//  11 12 13 null null 15