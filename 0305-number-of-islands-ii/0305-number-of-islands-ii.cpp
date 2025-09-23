// Approach: Disjoint Set Union (DSU)
// Time: O(L)
// Space: O(m*n)

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n, -1);
        size.resize(n, 0);
    }

    void makeSet(int u) {
        parent[u] = u;
        size[u] = 1;
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int count = 0;
        vector<int> ans;
        DSU dsu(m * n);

        vector<int> rowDelta = { 0, 0, -1, 1 };
        vector<int> colDelta = { -1, 1, 0, 0 };

        for (vector<int>& position: positions) {
            int row = position[0], col = position[1];
            int index = row * n + col;

            // skip repeated position
            if (dsu.parent[index] != -1) {
                ans.push_back(count);
                continue;
            }

            dsu.makeSet(index);
            
            unordered_set<int> neighborIslands;
            for (int i = 0; i < 4; i++) {
                int neiRow = row + rowDelta[i];
                int neiCol = col + colDelta[i];
                if (neiRow >= 0 && neiRow < m && neiCol >= 0 && neiCol < n) {
                    int neiIndex = neiRow * n + neiCol;
                    if (dsu.parent[neiIndex] != -1) {
                        neighborIslands.insert(dsu.find(neiIndex));
                        dsu.unite(index, neiIndex);
                    }
                }
            }

            if (neighborIslands.size() == 0) count++;
            else count -= neighborIslands.size() - 1;

            ans.push_back(count);
        }

        return ans;
    }
};

// 0 0 0 0 1 0
// 0 0 0 1 0 0
// 0 1 1 0 0 0