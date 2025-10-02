using PI2 = pair<int, int>;

class Solution {
public:
    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = { 0, 0, 1, -1 };

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        if (n == 0 || m == 0) return 0;

        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<PI2, vector<PI2>, greater<>> pq; // dist, position

        pq.push({ 0, 0 });
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [currentTime, position] = pq.top();
            int x = position / m, y = position % m;
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                return currentTime;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int newTime = max(currentTime, moveTime[nx][ny]) + 1;
                if (newTime < time[nx][ny]) {
                    time[nx][ny] = newTime;
                    pq.push({ time[nx][ny], nx * m + ny });
                }
            }            
        }

        return -1;
    }
};

// [[0,4],
//  [4,4]]

// pq = [(0,0)]

// pop (0,0), pq = []
// (1,0), weight = max(0, 4) + 1 = 5, 0 + 5 < INT_MAX, time[1][0] = 0 + 5 = 5 -> pq = [(5,2)]
// (0,1) -> pq = [(5,2), (5,1)]
