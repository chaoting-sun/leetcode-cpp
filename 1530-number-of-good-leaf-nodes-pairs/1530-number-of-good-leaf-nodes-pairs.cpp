// ## Understand

// 1. can the root be nullptr?
//  - No
// 2. what is the range of the distance? is it's value valid?
//  - 1 <= distance <= 10
// 3. what is the maximum number of nodes in the tree?
//  - the number of nodes is between [1, 2^20]

// ## Match and Plan

// The shortest path of two nodes in tree always go up to the lowest common ancestor. So, for
// each node, if it knows the distances from each leaf to its left child and right child, then
// the distances from both way can be compared to get those pairs with lower distance than the
// input distance.
// So, my plan is to use post-order traversal to make each node know the distance information
// from its children. I maintain two arrays left_distance and right_distance with length the input
// distance + 1 to record the count of the distance up to the left or right child of the current
// node. To count the good pairs, I iterate both the two arrays that satisfies (left distance + 1) +
// (right distance + 1) <= input distance.


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
    vector<int> countHelper(TreeNode* curr, int distance_bound, int& count) {
        vector<int> current_distance(distance_bound);

        if (!curr) return current_distance;

        // get the result from the left and right subtree
        vector<int> left_distance = countHelper(curr->left, distance_bound, count);
        vector<int> right_distance = countHelper(curr->right, distance_bound, count);

        // count the good pairs from the two subtree
        for (int i = 0; i < distance_bound; i++) {
            for (int j = 0; j < distance_bound; j++) {
                if (i + j + 2 <= distance_bound) {
                    count += left_distance[i] * right_distance[j];
                }
            }
        }

        // combine the two distances into one
        for (int i = 0; i < distance_bound - 1; i++) {
            current_distance[i + 1] += left_distance[i];
            current_distance[i + 1] += right_distance[i];
        }
        
        // add curr if it is a leaf
        if (!curr->left && !curr->right) {
            current_distance[0] = 1;
        }

        return current_distance;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        // dfs (post-order)
        int count = 0;
        countHelper(root, distance, count);
        return count;
    }
};


// Review

// TEST CASE: root = [1,2,3,null,4], distance = 3
//         1
//        2  3
//         \
//          4

// TRACE
// count = 0

// > countHelper(node 1, 3)
//   > countHelper(node 2, 3, 0)
//     > countHelper(null, 3, 0)
//       < return [0,0,0]
    
//     > countHelper(node 4, 3, 0)
//       - current_distance[0] = 1
//       - isLeaf = true
//       < return [1,0,0]
  
//     *process node 2
//       - left = [0,0,0], right = [1,0,0]
//       - count loop: i=0,j=0, 0+0+2<=3? No.
//       - shift loop: right[0] moves to the current[1]
//       - isLeaf = false
//       < return [0,1,0]

//   > countHelper(node 3, 3, 0)
//     > countHelper(null, 3, 0)
//       < return [0,0,0]
//     > countHelper(null, 3, 0)
//       < return [0,0,0]
    
//     *process node 3
//       - left = [0,0,0], right = [0,0,0]
//       - count loop: i=0,j=0, Cond: 2<=3? (yes), but left[0] is 0, so add 0
//       - shift loop: No updates.
//       - isLeaf = true
//       - current_distance[0] = 1
//       < returns [1,0,0]

//   *process node 1
//     - left = [0,1,0], right = [1,0,0]
//     - count loop: i=1,j=0, 1+0+2 <= 3? Yes. -> count = 1*1 = 1
//     - shift loop: current[2] = left[1], current[1] = right[0] -> current = [0,1,1]
//     - isLeaf = false
//     < returns[0,1,1]

// < final return: 1

// Evaluation
// Time: O(n*distance^2) = O(n)
// In the DFS, all nodes in the tree are visited. in every node, the count loop takes
// O(n squared).
// Space: O(n)
// The space is dominated by the depth of the tree, which may be skewwed like a linked list