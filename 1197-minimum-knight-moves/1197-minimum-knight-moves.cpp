class Solution {
public:
    uint64_t pack(int x, int y) {
        return (uint64_t)x << 32 | (uint32_t)y;
    }

    int minKnightMoves(int x, int y) {
        vector<int> dx = { 1, 2, 2, 1, -1, -2, -2, -1 };
        vector<int> dy = { 2, 1, -1, -2, -2, -1, 1, 2 };

        queue<pair<int,int>> q;
        unordered_set<uint64_t> visited;
        q.push({ 0, 0 });
        visited.insert(pack(0, 0));

        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [cx, cy] = q.front();
                q.pop();
                if (x == cx && y == cy) return moves;

                for (int i = 0; i < 8; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    uint64_t key = pack(nx, ny);
                    if (visited.count(key)) continue;

                    q.push({ nx, ny });
                    visited.insert(key);
                }
            }

            moves++;
        }
        return -1;
    }
};