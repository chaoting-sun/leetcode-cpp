class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<long long> distance(n + 1, INT_MAX);

        distance[k] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (vector<int>& time: times) {
                int u = time[0];
                int v = time[1];
                int w = time[2];

                if (distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        int min_time = INT_MIN;
        for (int i = 1; i <= n; i++) {
            // unreachable
            if (distance[i] == INT_MAX) {
                return -1;
            }
            min_time = max(min_time, (int)distance[i]);
        }

        return min_time;
    }
};