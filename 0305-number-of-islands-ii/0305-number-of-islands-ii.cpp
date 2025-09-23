// Approach: Disjoint Set Union (DSU)
// Time: O(m*n + L*alpha(mn))
// Space: O(m*n)

class DSU {
public:
    vector<int> parent, size;

    // O(m*n) to initialize parent and size
    DSU(int n) {
        parent.resize(n, -1);
        size.resize(n, 0);
    }

    bool isLand(int u) {
        if (parent[u] >= 0) {
            return true;
        } else {
            return false;
        }
    }

    void makeSet(int u) {
        parent[u] = u;
        size[u] = 1;
    }

    // union by size
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
            return true;
        }
        return false;
    }

    // path compression
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
};

class Solution {
    vector<array<int,2>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int count = 0;
        vector<int> ans;
        DSU dsu(m * n);

        // Time: O(L*alpha(mn))
        // There are L operations and the universe size (the max number of nodes is m*n)
        // for each operation we may do up to 4 union/finds. Each unite/find on a DSU with
        // union by size/rank + path compression is amortized O(alpha(mn)) 
        for (vector<int>& position: positions) {
            int row = position[0], col = position[1];
            int index = row * n + col;

            // skip repeated position
            if (dsu.parent[index] != -1) {
                ans.push_back(count);
                continue;
            }

            dsu.makeSet(index);
            count++;
            
            for (auto [dr, dc]: dirs) {
                int neiRow = row + dr;
                int neiCol = col + dc;
                if (neiRow >= 0 && neiRow < m && neiCol >= 0 && neiCol < n) {
                    int neiIndex = neiRow * n + neiCol;
                    if (dsu.isLand(neiIndex) && dsu.unite(index, neiIndex)) {
                        count--;
                    }
                }
            }
            ans.push_back(count);
        }

        return ans;
    }

};

// For future practice

// class Solution {
// public:
//     vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {

//     }
// };