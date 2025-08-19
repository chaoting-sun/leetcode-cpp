const int GATE = 0;
const int EMPTY = 2147483647;

class Solution {
public:
    // Intuition: we need to find the shortest path of each empty room to gate,
    // and BFS is a convenient algorithm to do this. in BFS, we push all gates
    // to the queue first, and then update the neigboring empty rooms. if an
    // empty room has been updated from a gate (A) ealier than the other gate (B),
    // it has bee updated to the smallest distance. otherwise it will be updated
    // later then B. Therefore, we don't have to update the empty room twice.
    
    // Approach: BFS

    // Time: O(m*n). BFS takes at most m*n steps to reach all rooms
    // Space: O(m*n). in worst case all are gates

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> pos;
        vector<int> di { -1, 1, 0, 0 };
        vector<int> dj { 0, 0, -1, 1 };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == GATE) {
                    pos.push({ i, j });
                }
            }
        }

        while (!pos.empty()) {
            int ci = pos.front().first;
            int cj = pos.front().second;
            pos.pop();

            for (int k = 0; k < 4; k++) {
                int ni = ci + di[k];
                int nj = cj + dj[k];

                if (ni < 0 || ni >= m || nj < 0 || nj >= n || rooms[ni][nj] != EMPTY)
                    continue;
                
                rooms[ni][nj] = rooms[ci][cj] + 1;
                pos.push({ ni, nj });
            }
        }
    }
};