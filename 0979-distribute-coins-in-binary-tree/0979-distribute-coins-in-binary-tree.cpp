// ## Understand

// What is the range of n? can it be empty?
//  - 1 <= node.val <= n

// Will the input be invalid? Such as that the sum of the node values is not the same as the number of nodes.
//  - The sum of all node.val is n


// ## Match

// One way is to move the coin one by one, and for each coin compute the movement, but it will takes O(N^2) time
// and the implementation is hard.
// Another way is to compute the excess or deficit of the subtree. For a subtree, it's balance can be computed by
// the balance of it's left subtree + the balance of it's right subtree + it's coin - 1. If the balance is positive
// the excessive coins must move up to it's parent. If the balance is negative its parent must pass the needed coins
// to the subtree. Therefore, the final total movement will be the sum of the absolute balances from each node.
// I will use post-order traversal to compute the balance of the subtree, and sums up the total absolute balances during
// traversal. This can be done in O(n)


// ## Plan

// I will use post-order traversal and use a global variable "movements" to sum the total movements. for each node,
// I compute it's balance as the left subtree balance + right subtree balance + it's coin + 1, update the movements
// by the absolute balance number, and then pass the balance to the parent. If the node is root, I will not update
// the movements because it has no parent to pass the coins.


// ## Implementation

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
    int sumTotalBalances(TreeNode* root, TreeNode* node, int& movements) {
        if (!node) return 0;

        int left_balance = sumTotalBalances(root, node->left, movements);
        int right_balance = sumTotalBalances(root, node->right, movements);
        int current_balance = left_balance + right_balance + node->val - 1;
        
        if (node != root) movements += abs(current_balance);
        return current_balance;
    } 

public:
    int distributeCoins(TreeNode* root) {
        int movements = 0;
        sumTotalBalances(root, root, movements);
        return movements;
    }
};


// Review

// base case:
//     1
// trace:
// movements = 0
// > sumTotalBalances(node(1), node(1))
//   cond: node is nullptr? no
//   compute left_balance
//      > sumTotalBalances(node(1), null)
//          < returns 0
//   compute right_balance
//      > sumTotalBalances(node(1), null)
//          < returns 0
//   current_balance = 0 + 0 + 1 - 1 = 0
//   cond: node != root? no
//   < returns 0
// < returns movements == 0

// test case:
//      1
//     / \
//    0   2
// trace
// movements = 0
// > sumTotalBalances(node(1))
//   cond: false
//   compute left_balance
//      > sumTotalBalances(node(0))
//        cond: false
//        compute left_balance
//          > sumTotalBalances(null)
//          < 0
//        compute right_balance
//          > sumTotalBalances(null)
//          < 0
//        current_balance = 0 + 0 + 0 - 1 = -1
//        cond: true -> movements = 1
//      < returns -1
//   compute right_balance
//      > sumTotalBalances(node(2))
//        cond: false
//        compute left_balance
//          > sumTotalBalances(null)
//          < 0
//        compute right_balance
//          > sumTotalBalances(null)
//          < 0
//        current_balance = 0 + 0 + 2 - 1 = 1
//        cond: true -> movement = 2
//      < returns 1
//   current_balance = 1 - 1 + 1 - 1 = 0
//   < 0
// ans: movements == 2


// Evaluation

// Time: O(n)
// all nodes will be visited once in the post-order traversal, and it takes O(1) to process the node
// Space: O(n)
// the recursion call stack takes O(n) for a skewed tree and O(logn) for a balanced tree