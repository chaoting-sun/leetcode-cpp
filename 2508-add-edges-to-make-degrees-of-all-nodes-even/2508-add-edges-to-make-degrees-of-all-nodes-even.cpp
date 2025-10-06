class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> nodes(n + 1);
        for (vector<int>& edge: edges) {
            int u = edge[0], v = edge[1];
            nodes[u].insert(v);
            nodes[v].insert(u);
        }

        vector<int> oddNodes;

        for (int i = 1; i <= n; i++) {
            if (nodes[i].size() % 2 == 1) {
                oddNodes.push_back(i);
            }
        }

        int nOdds = oddNodes.size();
        if (nOdds == 0) return true;
        if (nOdds != 2 && nOdds != 4) return false;

        unordered_set<int> oddNodesSet(oddNodes.begin(), oddNodes.end());

        if (nOdds == 2) {
            int u = oddNodes[0], v = oddNodes[1];
            if (!nodes[u].count(v)) return true;
            for (int i = 1; i <= n; i++) {
                if (!oddNodesSet.count(i) && !nodes[i].count(u) && !nodes[i].count(v)) {
                    return true;
                }
            }
            return false;
        } else {
            int u = oddNodes[0], v = oddNodes[1], x = oddNodes[2], y = oddNodes[3];
            if (
                (!nodes[u].count(v) && !nodes[x].count(y)) ||
                (!nodes[u].count(x) && !nodes[v].count(y)) ||
                (!nodes[u].count(y) && !nodes[v].count(x))
            ) {
                return true;
            } else {
                return false;
            }
        }
    }
};


// class Solution {
// public:
//     bool isPossible(int n, vector<vector<int>>& edges) {
//         vector<unordered_set<int>> nodes(n + 1);
//         for (vector<int>& edge: edges) {
//             int u = edge[0], v = edge[1];
//             nodes[u].insert(v);
//             nodes[v].insert(u);
//         }

//         int nodeIndex = -1;
//         for (int i = 1; i <= n; i++) {
//             if (nodes[i].size() % 2 == 1) {
//                 nodeIndex = i;
//                 break;
//             }
//         }
//         if (nodeIndex == -1) return true;

//         for (int i = nodeIndex + 1; i <= n; i++) {
//             if (nodes[i].size() % 2 == 1 && !nodes[i].count(nodeIndex)) {
//                 nodes[i].insert(nodeIndex);
//                 nodes[nodeIndex].insert(i);
//                 break;
//             } else {
//                 if (i == n) return false;
//             }
//         }

//         for (int i = nodeIndex + 1; i <= n; i++) {
//             if (nodes[i].size() % 2 == 1) {
//                 nodeIndex = i;
//                 break;
//             } else {
//                 if (i == n) return true;
//             }
//         }

//         for (int i = nodeIndex + 1; i <= n; i++) {
//             if (nodes[i].size() % 2 == 1 && !nodes[i].count(nodeIndex)) {
//                 nodes[i].insert(nodeIndex);
//                 nodes[nodeIndex].insert(i);
//                 break;
//             } else {
//                 if (i == n) return false;
//             }
//         }

//         for (int i = nodeIndex + 1; i <= n; i++) {
//             if (nodes[i].size() % 2 == 1) return false;
//         }

//         return true;
//     }
// };