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

// ## understand

// - can the traversal be empty?
//  -> no
// - what is the range of the values?
//  -> 1 <= val <= 10^9
// - what is the number of nodes?
//  -> 1 <= # nodes <= 1000


// ## match and plan

// It seems like the problem can be solved by DFS, given that the traversal string is
// a preorder traversal. I will do DFS from the first node. In each node, I compute
// the number of dash before the node. If the count is not the expected number, then
// this node belongs to another subtree. If it is the expected number, then we compute
// the node value, create a node, do DFS into its left and right node, and return the node.


// Implementation

class Solution {
private:
    TreeNode* Dfs(const string& traversal, int& index, int expected_depth) {
        int dash_count = 0;
        while (index + dash_count < traversal.size() && traversal[index + dash_count] == '-') {
            dash_count++;
        }

        if (dash_count != expected_depth) {
            return nullptr;
        }

        index += dash_count;

        int value = 0;
        while (index < traversal.size() && isdigit(traversal[index])) {
            value = value * 10 + (traversal[index] - '0');
            index++;
        }
    
        TreeNode* node = new TreeNode(value);
        node->left = Dfs(traversal, index, expected_depth + 1);
        node->right = Dfs(traversal, index, expected_depth + 1);

        return node;
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        if (traversal.empty()) return nullptr;
        int index = 0;
        return Dfs(traversal, index, 0);
    }
};


// Review

// traversal = "1-2--3"
// - Dfs(index=0, 0)
// dash_count = 0 -> dash_count = 0
// index = 0
// value = 1
// index = 1
// node(val=1)
//  left->
//  - Dfs(index=1, 1)
//    dash_count = 0 -> dash_count = 1
//    index = 1 + 1 = 2
//    value = 2
//    index = 3
//    node(val=2)
//     left->
//     - Dfs(index=3, 2)
//       dash_count = 0 -> 2
//       index = 3 + 2 = 5
//       value = 3
//       index = 6
//       node(val=3): left->nullptr, right->nullptr
//     right->nullptr
// right->nullptr


// Evaluate