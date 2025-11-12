class Solution {
public:
    uint64_t pack(int x, int y) {
        return (uint64_t)x << 32 | (uint32_t)y;
    }

    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;

        vector<int> dx = { 1, 2, 2, 1, -1, -2, -2, -1 };
        vector<int> dy = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int directions = 8;

        queue<pair<int,int>> q1, q2;
        unordered_set<uint64_t> fronts, ends;
        
        q1.push({ 0, 0 });
        q2.push({ x, y });
        fronts.insert(pack(0, 0));
        ends.insert(pack(x, y));
        int moves = 1;

        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                swap(fronts, ends);
            }
            
            int sz = q1.size();
            while (sz--) {
                auto [cx, cy] = q1.front();
                q1.pop();
                for (int i = 0; i < directions; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    uint64_t key = pack(nx, ny);
                    if (ends.count(key)) return moves;

                    if (fronts.count(key)) continue;
                    q1.push({ nx, ny });
                    fronts.insert(pack(nx, ny));
                }
            }

            moves++;
        }

        return -1;
    }
};