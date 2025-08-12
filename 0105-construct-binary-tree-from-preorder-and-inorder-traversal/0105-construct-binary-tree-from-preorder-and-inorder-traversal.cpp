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
    // Approach1: Recursion. Find the first element in preorder array as the root, and find the position of
    // the value in the inorder array, in which the left side is the nodes in left subtree and right side
    // the right subtree. we create a node for this element, and recursively solve its left and right node.
    // Time: O(n^2) in worst case the tree is left skewed. so every
    // Space: O(1)

    // TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
    //     // base case
    //     if (pre_l > pre_r) return nullptr;
        
    //     // the root between the subtree
    //     int curr_val = preorder[pre_l];
        
    //     // sequentially find the position of the root
    //     int pos = in_l;
    //     while (pos <= in_r) {
    //         if (curr_val == inorder[pos]) break;
    //         pos++;
    //     }

    //     TreeNode* node = new TreeNode(curr_val);

    //     int n_left = pos - in_l; // # nodes that is at the left of pos in inorder
    //     int n_right = in_r - pos; // # nodes that is at the right of pos in inorder

    //     node->left = recursion(preorder, inorder, pre_l + 1, pre_l + n_left, in_l, pos - 1);
    //     node->right = recursion(preorder, inorder, pre_l + 1 + n_left, pre_r, pos + 1, in_r);
    //     return node;
    // }

    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     int n = preorder.size();
    //     return recursion(preorder, inorder, 0, n - 1, 0, n - 1);
    // }

    // Approach2: 
    // Optimize from the previous solution. In previous method we need O(n) to find the index of current node in inorder,
    // We can firstly construct a hashmap for inorder (value -> index) to decrease the time to O(1)
    // Also, we can handle the root in the order of preorder as for any current node its parent has been handled (except root)
    // Time: O(n)
    // Space: O(n)

    unordered_map<int, int> inorder_map;
    int preorder_i = 0;

    TreeNode* arrayToTree(vector<int>& preorder, int inorder_l, int inorder_r) {
        if (inorder_l > inorder_r) return nullptr;

        int curr = preorder[preorder_i];
        preorder_i++;

        int inorder_pos = inorder_map[curr];
        TreeNode* node = new TreeNode(curr);
        node->left = arrayToTree(preorder, inorder_l, inorder_pos - 1);
        node->right = arrayToTree(preorder, inorder_pos + 1, inorder_r);
        return node;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) inorder_map[inorder[i]] = i;
        return arrayToTree(preorder, 0, n - 1);
    }
};