class Solution {
public:
    // Approach: Bellman-Ford Algorithm
    
    // “At most k stops” ⇒ at most k+1 edges (flights).
    // Bellman–Ford guarantees: after the i-th round, distances use ≤ i edges.
    // So we run k+1 rounds (instead of V-1) and, in each round, we must read from the previous layer and write into a new layer.
    // This prevents chaining multiple new edges within the same round.
    // Implement this by keeping dist (read-only for the round) and next (the updated distances for this round). Initialize next = dist each round.

    // Time: O(V + E)
    // Space: O(V)

    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     vector<int> dist(n, INT_MAX);

    //     dist[src] = 0;

    //     for (int i = 0; i < k + 1; i++) {
    //         // Time: O(V)
    //         vector<int> updated_dist(dist);
            
    //         // Time: O(E)
    //         for (vector<int>& flight: flights) {
    //             int u = flight[0], v = flight[1], w = flight[2];
    //             if (dist[u] != INT_MAX && dist[u] + w < updated_dist[v]) {
    //                 updated_dist[v] = dist[u] + w;
    //             }
    //         }

    //         dist = updated_dist;
    //     }

    //     return dist[dst] == INT_MAX ? -1 : dist[dst];
    // }

    // Approach: Dijkstra's Algorithm

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto flight: flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            adj[u].push_back({ v, w });
        }

        using State = array<int, 3>; // 3 elements: cost, vertex, times
        priority_queue<State, vector<State>, greater<State>> pq;
        vector<vector<int>> best_cost(n, vector<int>(k + 2, INT_MAX));

        best_cost[src][0] = 0;
        pq.push({ 0, src, 0 });

        while (!pq.empty()) {
            auto [dist, u, time] = pq.top();
            pq.pop();
            
            if (u == dst) return dist;
            if (dist != best_cost[u][time]) continue;
            if (time == k + 1) continue;

            int next_time = time + 1;
            for (auto [v, w]: adj[u]) {
                if (dist + w < best_cost[v][next_time]) {
                    best_cost[v][next_time] = dist + w;
                    pq.push({ best_cost[v][next_time], v, next_time });
                }
            }
        }

        return -1;
    }
};

// test 1:
// n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1

// dist = [0, inf, inf, inf]

// i = 0
// dist = [0, 100, inf, inf]

// i = 1
// dist = [0, 100, 200, 700]