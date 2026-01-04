class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<int> available;
        for (const string& word: words) {
            for (char ch: word) {
                available.insert(ch - 'a');
            }
        }

        vector<vector<int>> adj(26);
        vector<int> in_degree(26);
        vector<bool> required(26);

        for (int i = 0; i < words.size() - 1; i++) {
            string prev = words[i];
            string curr = words[i + 1];
            int min_length = min(prev.size(), curr.size());
            for (int j = 0; j < min_length; j++) {
                if (prev[j] != curr[j]) {
                    adj[prev[j] - 'a'].push_back(curr[j] - 'a');
                    in_degree[curr[j] - 'a']++;

                    required[prev[j] - 'a'] = true;
                    required[curr[j] - 'a'] = true;
                    break;
                } else {
                    // ab should be before abc
                    if (j == min_length - 1 && prev.size() > curr.size()) {
                        return "";
                    }
                }
            }
        }

        int required_count = 0;
        for (int i = 0; i < 26; i++) {
            if (required[i]) required_count++;
        }

        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (in_degree[i] == 0 && required[i]) q.push(i);
        }

        string result = "";

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr + 'a');
            available.erase(curr);

            for (int nxt: adj[curr]) {
                in_degree[nxt]--;
                if (in_degree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        if (result.size() != required_count) {
            return "";
        }

        for (const char& ch: available) {
            result.push_back(ch + 'a');
        }
        return result;
    }
};

// Submit Error
// q.push_back(nxt); -> q.push(nxt);


// test case: ['ab', 'bc', 'bd', 'bde'] -> (a b) (c d) (e)
// trace:
// available = { 0, 1, 2, 3, 4 }
// adj[0] = [1]
// in_degree = [0 1 0 0 0]
// adj[2] = [3]
// in_degree = [0 1 0 1 0]
// required = [t t t t f]
// required_count = 5
// q = [0 2]
// curr = 0
// q = [2]
// result = a
// available = { 1, 2, 3, 4 }
// in_degree = [0 0 0 1 0]
// nei -> q = [2 1]
// curr = 2
// q = [1]
// result = ac
// available = { 1, 3, 4 }
// nei -> q = [1 3]
// in_degree = [0 0 0 0 0] -> push: q = [1 3]
// curr = 1
// q = [3]
// result = acb
// available = { 3, 4 }
// in_degree = [0 0 0 0 0]
// curr = 3
// q = []
// result = acbd
// available = { 4 }
// result = acbde
// < returnc acbde

// test case: ['ab', 'a'] -> ""
// trace:
// a == a, j == 0, 2 > 1 -> returns ""

// test case: ['ba', 'ab'] -> ""
// trace:
// j = 0, 1
// adj[1] = [0], adj[0] = [1]
// in_degree = [1, 1]
// required = 2
// 0 != 2 -> returns ""