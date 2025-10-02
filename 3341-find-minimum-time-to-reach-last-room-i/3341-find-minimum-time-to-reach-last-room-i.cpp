using PI2 = pair<int, int>;

class Solution {
public:
    // Approach: dijkstra
    // Time: O(mn*log(mn)). There are nm points and O(mn) edges. Dijkstra's algorithm
    // using a min heap performs at most O(nm) insertions and deletions. Each heap op
    // takes O)(log(mn))
    // Space: O(mn)

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

    // Practice

    // int minTimeToReach(vector<vector<int>>& moveTime) {

    // }
};