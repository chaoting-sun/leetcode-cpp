class Solution {
public:
    // Topological Sort (Kahn's Algorithm)
    // Time: O(|word_{0}|+...+|word_{n-1}|)
    // Space: O(V + E). V is the number of different characters.

    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> order;
        // indegree for every seen char
        unordered_map<char, int> indegree;

        // Time: O(|word_{0}|+...+|word_{n-1}|)
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string& a = words[i];
            string& b = words[i + 1];
            int min_size = min(a.size(), b.size());

            // find first different char
            int j = 0;
            while (j < min_size && a[j] == b[j]) j++;

            // all equal up to min length. if a is longer, it's invalid
            if (j == min_size) {
                if (a.size() > b.size()) return "";
            } else {
                order[a[j]].insert(b[j]);
            }
        }

        for (const string& word: words) {
            for (char c: word) {
                if (!indegree.count(c)) indegree[c] = 0;
            }
        }

        for (auto& [c1, c2set]: order) {
            for (char c2: c2set) {
                indegree[c2]++;   
            }
        }

        queue<char> q;
        for (auto& [c, deg]: indegree) {
            if (deg == 0) q.push(c);
        }

        // Time: O(V + E). for every character it may be recorded to be in front of all the other characters
        // V = 26 at most, and E = 26 * 25 at most, which is small
        string ans = "";
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            ans += u;
            for (char v: order[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // if there is any cycle, it's invalid
        if (ans.size() < indegree.size()) return "";
        return ans;
    }
};

