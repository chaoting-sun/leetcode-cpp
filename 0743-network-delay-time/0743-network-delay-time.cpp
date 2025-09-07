class Solution {
public:
    // Bellman-Ford Algorithm
    // Time: O(EV)
    // Space: O(V)

    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //     vector<int> distance(n + 1, INT_MAX);

    //     distance[k] = 0;

    //     for (int i = 0; i < n - 1; i++) {
    //         for (vector<int>& time: times) {
    //             int u = time[0];
    //             int v = time[1];
    //             int w = time[2];

    //             if (distance[u] != INT_MAX && distance[v] > distance[u] + w) {
    //                 distance[v] = distance[u] + w;
    //             }
    //         }
    //     }

    //     int min_time = INT_MIN;
    //     for (int i = 1; i <= n; i++) {
    //         // unreachable
    //         if (distance[i] == INT_MAX) {
    //             return -1;
    //         }
    //         min_time = max(min_time, distance[i]);
    //     }

    //     return min_time;
    // }

    // Dijkstra
    // Time: O((V + E) logE)
    // Space: O(E + V)

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (vector<int> &time: times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({ v, w });
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(n + 1, INT_MAX);

        distance[k] = 0;
        pq.push({ 0, k });

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            for (auto& [v, w]: adj[u]) {
                if (d + w < distance[v]) {
                    distance[v] = d + w;
                    pq.push({ d + w, v });
                }
            }
        }

        int max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) return -1;
            max_time = max(max_time, distance[i]);
        }
        return max_time;
    }
};