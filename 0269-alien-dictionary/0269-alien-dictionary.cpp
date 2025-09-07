class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> order;

        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            int min_len = min(words[i].size(), words[i + 1].size());
            if (words[i].substr(0, min_len) == words[i + 1].substr(0, min_len) && words[i].size() > words[i + 1].size()) {
                return "";
            }
            for (int j = 0; j < min_len; j++) {
                if (words[i][j] != words[i + 1][j]) {
                    order[words[i][j]].insert(words[i + 1][j]);
                    break;
                }
            }
        }

        unordered_map<char, int> indegree;
        for (int i = 0; i < n; i++) {
            for (char ch: words[i]) {
                if (!indegree.count(ch)) indegree[ch] = 0;
            }
        }

        for (auto& [c1, c2set]: order) {
            for (char c2: c2set) {
                indegree[c2]++;   
            }
        }

        queue<char> q;
        for (auto& [c, cnt]: indegree) {
            if (cnt == 0) q.push(c);
        }

        string ans = "";
        while (!q.empty()) {
            char c1 = q.front();
            q.pop();
            ans += c1;
            for (char c2: order[c1]) {
                indegree[c2]--;
                if (indegree[c2] == 0) {
                    q.push(c2);
                }
            }
        }

        if (ans.size() < indegree.size()) return "";
        return ans;
    }
};


// i=0
// ["wrt","wrf","er","ett","rftt"]

// w -> e
// e -> r

// i=1
// ["wrt","wrf"]

// i=2
// ["wrt","wrf"]
// t -> f

// i=1
// ["er","ett"]
// r -> t

// i=2
// x

// i=1
// ["rftt"]
// x