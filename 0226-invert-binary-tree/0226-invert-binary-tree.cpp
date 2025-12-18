// Plan
// recursively traverse the tree
// for each node, swap the left subtree root and right subtree root.

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
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) return nullptr;
        
    //     TreeNode* left_child = invertTree(root->left);
    //     TreeNode* right_child = invertTree(root->right);
    //     root->left = right_child;
    //     root->right = left_child;

    //     return root;
    // }

    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        stack<TreeNode*> todo_list;
        
        todo_list.push(root);
        while (!todo_list.empty()) {
            TreeNode* node = todo_list.top();
            todo_list.pop();

            swap(node->left, node->right);
            if (node->left) todo_list.push(node->left);
            if (node->right) todo_list.push(node->right);
        }
        return root;
    }
};

//     1
//   2
// 3

// > invertTree(node(1))
//     left_child =
//         > invertTree(node(2))
//             left_child =
//                 > invertTree(node(3))
//                     left_child =
//                         invertTree(null)
//                         < null
//                     right_child =
//                         invertTree(null)
//                         < null
//                     node(3)->left = null
//                     node(3)->right = null
//                     < node(3)
//             right_child =
//                 > invertTree(null)
//                     < null
//             node(2)->left = null
//             node(2)->right = node(3)
//             < node(2)
//     right_child =
//         invertTree(null)
//     node(1)->right = node(2)
//     node(1)->left = null
//     < node(1)
