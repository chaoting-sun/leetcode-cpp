// ## Understand

// What is the range of the length of preorder and postorder?
// - 1 <= length of preorder <= 30

// Can the preorder and postorder be invalid such that we cannot construct the binary tree?
// - it is guaranteed that the binary tree can be constructed


// Match

// To construct the binary tree, I will use DFS. In each recursion, I will find the root first,
// which is at the start of the preorder traversal, while at the end of the postorder traversal.
// Then, I will use the root of the left subtree to divide the remaining nodes into left and right
// subtree, because it will be the next node of the root in the preorder traversal, and the last
// node of the left subtree in the postorder traversal. This method can be done as there are no
// repetitive numbers.


// Plan

// My plan is maintain the left and right pointers for both traversals: left_pre, right_pre,
// left_post, right_post at the left most and right most index. Every time in the recursive function,
// if left_pre is not larger than right_pre, then
// 1. I create a root node for the preorder[left_pre]
// 2. Then, the next node preorder[left_pre + 1] is the root of left subtree. I use its
// value to find the value index j in the postorder.
// 3. Then, I recursively call the function for the left subtree and right subtree, and set the
// left and right child of the root to be their returned nodes
// 4. Finally, the function returns the root.


// Implementation

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int node_count = preorder.size();
        
        unordered_map<int,int> post_index;
        for (int i = 0; i < node_count; i++) post_index[postorder[i]] = i;

        auto construct = [&](auto&& self, int pre_left, int pre_right, int post_left, int post_right) -> TreeNode* {
            if (pre_left > pre_right) return nullptr;
            
            TreeNode* node = new TreeNode(preorder[pre_left]);
            if (pre_left == pre_right) return node;

            int left_child_value = preorder[pre_left + 1];
            int left_subtree_size = post_index[left_child_value] - post_left + 1;
            
            node->left = self(self,
                              pre_left + 1, pre_left + left_subtree_size,
                              post_left, post_left + left_subtree_size - 1);
            node->right = self(self, 
                               pre_left + left_subtree_size + 1, pre_right,
                               post_left + left_subtree_size, post_right - 1);
            return node;
        };

        TreeNode* root = construct(construct, 0, node_count - 1, 0, node_count - 1);
        return root;
    }
};


// Review

// base case: preorder = [1], postorder = [1]
// trace:
// node_count = 1
// > constructBinaryTree(0,0,0,0)
//  - root = TreeNode(1)
//  < returns TreeNode(1)

// test case: preorder = [1,2,3], postorder = [2,3,1]
// trace:
// node_count = 3
// > build post_index
//  - i=0, post_index[2] = 0
//  < post_index = { 2: 0, 3: 1, 1: 2 }
// > construct(0, 2, 0, 2)
//  - node = new TreeNode(1)
//  - cond: 0 == 2 ? No.
//  - left_child_value = 2
//  - left_subtree_size = post_index[2] - 0 + 1 = 1
//  - node->left = construct(1, 1, 0, 0)
//      - node = new TreeNode(2)
//      < returns node(2)
//  - node-right = construct(2, 2, 1, 1)
//      - node = new TreeNode(3)
//      < returns node(3)
//  < return node(1); node->left = node(2); node->right= node(3)


// Evaluation

// Time: O(n)
//  - building a hashmap costs O(n)
//  - contructing the tree costs O(n) in worst case for a skewed tree
// Space: O(n)
//  - hashmap costs O(n)
//  - the construction will cost O(n) recursive call stack for a skewed tree


// Submit Errors

// 1. spell wrong
// left_pre
// to
// pre_left

// 2. No ";" after lambda function

// 3. heap-buffer-overflow
