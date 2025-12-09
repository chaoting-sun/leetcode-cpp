

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // build an adjacency list
        // notice that it's a undirected graph
        vector<vector<int>> adj(n + 1);
        for (const auto& dislike: dislikes) {
            int u = dislike[0], v = dislike[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (colors[i] != 0) continue;
            
            queue<pair<int,int>> nodes;
            nodes.push({ i, 1 });
            colors[i] = -1;
            
            while (!nodes.empty()) {
                auto [u, next_color] = nodes.front();
                nodes.pop();
                
                for (int v: adj[u]) {
                    if (colors[v] == 0) {
                        colors[v] = next_color;
                        nodes.push({ v, -next_color });
                    } else if (colors[v] != next_color) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};