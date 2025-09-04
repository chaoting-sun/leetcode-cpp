// Euler's path: current location + path2 + path1

class Solution {
    unordered_map<string,queue<string>> Map;

public:
    vector<string> dfs(string& start) {
        vector<vector<string>> paths;
        while (!Map[start].empty()) {
            string to = Map[start].front();
            Map[start].pop();
            paths.push_back(dfs(to));
        }

        vector<string> res{ start };
        for (int i = paths.size() - 1; i >= 0; i--) {
            for (auto& path: paths[i]) {
                res.push_back(path);
            }
        }
        return res;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        for (auto& ticket: tickets) {
            Map[ticket[0]].push(ticket[1]);
        }

        string start = "JFK";
        return dfs(start);
    }
};