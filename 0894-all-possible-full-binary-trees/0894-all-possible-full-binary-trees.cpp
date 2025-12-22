// ## Understand

// what is the range of n? can it be invalid or 0?
// - 1 <= n <= 20


// ## Match

// To build a full binary tree, n must be odd, because for each node, they have 0 or 2 children.
// So, if n is even then I return with empty vector.
// For a full binary tree, its subtree is also full binary tree. So the subtree must also have
// odd number of nodes. Based on this, my strategy will be recursively construct the binary tree.
// For each recursive call, I create the current node, and distribute all possibilities of
// both subtrees such that both number is odd.


// ## Plan

// Firstly, if n is even, I return with empty vector.
// If n is odd, I will use a dfs function to recurively contruct the full binary tree.
// For each recursive call, I pass the remaining node number, create a new node for each possibilities
// of the left and right subtree, where the number of nodes for the subtree is odd. when, n is 0,
// I early terminate the call.


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
private:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> constructFBT(int remaining_node_count) {
        if (remaining_node_count == 0) return {};

        vector<TreeNode*> result;
        
        if (memo.count(remaining_node_count)) {
            return memo[remaining_node_count];
        }
        
        // base case
        if (remaining_node_count == 1) {
            TreeNode* root = new TreeNode(0);
            result.push_back(root);
        }

        remaining_node_count--; // the current node
        for (int i = 1; i < remaining_node_count; i += 2) {
            int left_node_count = i;
            int right_node_count = remaining_node_count - i;
            
            vector<TreeNode*> left_nodes = constructFBT(left_node_count);
            vector<TreeNode*> right_nodes = constructFBT(right_node_count);
            
            for(int j = 0; j < left_nodes.size(); j++) {
                for (int k = 0; k < right_nodes.size(); k++) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left_nodes[j];
                    root->right = right_nodes[k];
                    result.push_back(root);
                }
            }
        }
        return memo[remaining_node_count] = result;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        return constructFBT(n);
    }
};

// Review

// test case: n = 10
// trace: n % 2 == 0 -> return {}

// test case: n = 1
// result = []
// > constructFBT(n=1, true)
//  remaining_node_count == 1
//  root = node(0)
//  result = [node(0)]
// < returns [node(0)]

// test case: n = 3
// result = []
// > constructFBT(n=5, is_root=true)
//  cond: remaining_node_count == 1? no
//  remaining_node_count = 2
//  for loop
//      i = 1
//      left_node_count = 1
//      right_node_count = 1
//      root = node(0)
//      root->left = constructFBT(1, result, false)
//          cond: remaining_node_count == 1? yes
//          root = node(0)
//          < returns node(0)
//      root->right = constructFBT(1, result, false)
//          cond: remaining_node_count == 1? yes
//          root = node(0)
//          < returns node(0)
//      cond: is_root == true -> result = [node(0)]
// < returns result = [node(0)]

// test case: n = 5
// trace:
// allPossibleFBT(n = 5)
// > constructFBT(n=5, is_root=true)
//  result = {}
//  remaining_node_count = 4
//  > for loop
//      i = 1
//      left_node_count = 1
//      right_node_count = 3
//      left_nodes = constructFBT(1)
//          > constructFBT(1)
//              root = node(0)
//              < returns [root]
//      right_nodes = constructFBT(3)
//          > constructFBT(3)
//              remaining_node_count = 2
//              > for loop
//                  i = 1
//                  left_node_count = 1
//                  right_node_count = 1
//                  left_nodes = constructFBT(1) = node(0)
//                  right_nodes = constructFBT(1) = node(0)
//                  j = 0, k = 0
//                  root = node(0)
//                  root->left = node(0)
//                  root->right = node(0)
//                  result = [root]
//              < returns [root]
//      j = 0, k = 0
//      root = node(0)
//      root->left = node(0)
//      root->right = node(0)
//      result = [root]
//      
//      i = 3
//      left_node_count = 3
//      right_node_count = 1
//      left_nodes = [node(0)], node(0)->left = node(0), node(0)->right = node(0)
//      right_nodes = [node(0)]
//      result = [root, root]
//  < [root, root]

// Evaluation

// Time: ?
// Space: ?


// Submit Error

// CE:  use of undeclared identifier 'root' (return root)
// the whole logic is wrong:
// class Solution {
// public:
//     TreeNode* constructFBT(int remaining_node_count, vector<TreeNode*>& result, bool is_root) {
//         if (remaining_node_count == 0) return nullptr;

//         // base case
//         if (remaining_node_count == 1) {
//             TreeNode* root = new TreeNode(0);
//             if (is_root) result.push_back(root);
//             return root;
//         }

//         remaining_node_count--; // the current node

//         for (int i = 1; i < remaining_node_count; i += 2) {
//             int left_node_count = i;
//             int right_node_count = i - remaining_node_count;

//             TreeNode* root = new TreeNode(0);
//             root->left = constructFBT(left_node_count, result, false);
//             root->right = constructFBT(right_node_count, result, false);

//             if (is_root) result.push_back(root);

//         }

//         return root;
//     }

// public:
//     vector<TreeNode*> allPossibleFBT(int n) {
//         if (n % 2 == 0) return {};
//         vector<TreeNode*> result;
//         constructFBT(n, result, true);
//         return result;
//     }
// };

// CE: too many arguments to function call
// return constructFBT(n, true);
// to
// return constructFBT(n);

// RE: AddressSanitizer: heap-buffer-overflow
// for(int j = 0; j < left_node_count; j++) {
// to
// for(int j = 0; j < left_nodes.size(); j++) {