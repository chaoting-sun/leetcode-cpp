class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendsLookup;
        for (auto& deadend: deadends) {
            deadendsLookup.insert(deadend);
        }

        string start = "0000";
        queue<string> q;
        unordered_set<string> visited;

        if (deadendsLookup.count(start)) return -1;

        q.push(start);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string s = q.front();
                q.pop();
                if (s == target) return steps;

                for (string nei: getNeighbors(s)) {
                    if (!deadendsLookup.count(nei) && !visited.count(nei)) {
                        q.push(nei);
                        visited.insert(nei);
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    vector<string> getNeighbors(string& s) {
        vector<string> result;
        for (int i = 0; i < 4; i++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string nei = s;
                nei[i] = (nei[i] - '0' + 10 + diff) % 10 + '0';
                result.push_back(nei);
            }
        }
        return result;
    }
};