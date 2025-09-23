class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;

    void unionSet(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }

    int findSet(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findSet(parent[u]);
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int count = 0;
        vector<int> ans;

        vector<int> rowDelta = { 0, 0, -1, 1 };
        vector<int> colDelta = { -1, 1, 0, 0 };

        for (vector<int>& position: positions) {
            int row = position[0], col = position[1];
            int index = row * n + col;

            // skip repeated position
            if (parent.count(index)) {
                ans.push_back(count);
                continue;
            }

            parent[index] = index;
            size[index] = 1;
            
            unordered_set<int> neighborIslands;
            for (int i = 0; i < 4; i++) {
                int neiRow = row + rowDelta[i];
                int neiCol = col + colDelta[i];
                if (neiRow >= 0 && neiRow < m && neiCol >= 0 && neiCol < n) {
                    int neiIndex = neiRow * n + neiCol;
                    if (parent.count(neiIndex)) {
                        neighborIslands.insert(findSet(neiIndex));
                        unionSet(index, neiIndex);
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