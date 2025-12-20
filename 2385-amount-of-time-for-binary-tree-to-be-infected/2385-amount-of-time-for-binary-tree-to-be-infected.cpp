// ## Understand

// Are the values on each node unique?
//  - yes
// How many nodes at most are in the tree?
//  - 10^5
// Can this tree be empty?
//  - no
// Can start be invalid?
//  - a node with a value of start exists in the tree


// ## Match

// This problem essentially asks the distance between the start node and the farthest node from it.
// But the difficulty is that we cannot simply use BFS from the start node as the tree can be seen
// as a directed graph.
// So, I will treat the tree as an undirected graph, creating data structure that records the neighbors
// of each node using map. Then, I start a BFS from the start node layer by layer get the distance of its
// farthest node


// ## Plan

// My plan has two parts
// First, I initialize a map that records the node connections. Then, I run a DFS from the root, building
// the map.
// Second, I run a BFS using the map layer by layer. I count the distance for each layer. The distance will
// the minutes needed for the entire tree to be infected.


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
    void buildAdj(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if (!root) return;

        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right;

        if (left_node) {
            adj[root->val].push_back(left_node->val);
            adj[left_node->val].push_back(root->val);
            buildAdj(left_node, adj);
        }

        if (right_node) {
            adj[root->val].push_back(right_node->val);
            adj[right_node->val].push_back(root->val);
            buildAdj(right_node, adj);
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;

        // build a map
        // the node value are unique so we can use the values
        unordered_map<int, vector<int>> adj;
        buildAdj(root, adj);
        
        unordered_set<int> visited;

        // run a BFS
        queue<int> nodeToProcess;
        int distance = 0;

        nodeToProcess.push(start);
        visited.insert(start);
        
        while (!nodeToProcess.empty()) {
            int size = nodeToProcess.size();
            for (int i = 0; i < size; i++) {
                int curr = nodeToProcess.front();
                nodeToProcess.pop();
                for (int neighbor: adj[curr]) {
                    if (visited.count(neighbor)) continue;
                    nodeToProcess.push(neighbor);
                    visited.insert(neighbor);
                }
            }
            distance++;
        }

        return distance - 1;
    }
};


// Review

// test case:
// tree:
//     1
// start: 1
// trace:
// > buildAdj(node(1))
// nodeToProcess = [1]
// visited = { 1 }
// > while loop
//  size = 1
//  i = 0
//  curr = 1
// < returns distance = 0

// test case:
// tree:
//     1
//   2   3
// start: 3
// trace:
// > buildAdj(node(1))
//  left_node = node(2)
//  right_node = node(3)
//  adj[1] = [2], adj[2] = [1]
//  adj[1] = [2,3], adj[3] = [1]
// nodeToProcess = [3]
// visited = { 3 }
// distance = 0
// > while loop
//  size = 1
//  i = 0
//      curr = 3
//      nodeToProcess = []
//      neighbor = 1
//      nodeToProcess = [1]
//      visited = { 3, 1 }
//  distance = 1
//  size = 1
//  i = 0
//      curr = 1
//      nodeToProcess = []
//      neighbor = 2
//      nodeToProcess = [2]
//      visited = { 3, 1, 2 }
//  i = 1
//      curr = 3 -> has been visited
//  distance = 2
//  < returns distance (2)


// Evaluation

// Time: O(nlogn)
//  build adj: there are n nodes, and each push takes O(logn) -> O(nlogn)
//  BFS: n nodes are pushed and popped one time and n - 1 edges are visited -> O(nlogn)
// Space: O(n)
//  adj: n nodes and n - 1 edges -> O(n)
//  BFS: O(n) for queue


// Submit Errors

// error: no viable conversion from 'TreeNode *' to 'TreeNode'
// TreeNode left_node = root->left;
// to
// TreeNode* left_node = root->left;

// error: use of class template 'map' requires template arguments
// for (int neighbor: map[curr]) {
// to
// for (int neighbor: adj[curr]) {

// Wrong answer
// 1.
// if (!visited.count(neighbor)) continue;
// to
// if (visited.count(neighbor)) continue;
// 2.
//     if (size > 0) distance++;
// }
// return distance;
// to
//     distance++;
// }
// return distance - 1;
// 3.
// adj[left_node->val].push_back(left_node->val);
// to
// adj[left_node->val].push_back(root->val);
