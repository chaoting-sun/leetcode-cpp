class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        for (int i = 0; i < k + 1; i++) {
            vector<int> updated_dist(dist);

            for (vector<int>& flight: flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if (dist[u] != INT_MAX && dist[u] + w < updated_dist[v]) {
                    updated_dist[v] = dist[u] + w;
                }
            }

            dist = updated_dist;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// test 1:
// n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1

// dist = [0, inf, inf, inf]

// i = 0
// dist = [0, 100, inf, inf]

// i = 1
// dist = [0, 100, 200, 700]