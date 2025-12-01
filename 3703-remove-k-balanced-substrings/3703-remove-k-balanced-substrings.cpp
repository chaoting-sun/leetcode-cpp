class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        if (n == 0) return "";

        vector<pair<char, int>> p;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) {
                count++;
            } else {
                p.push_back({ s[i - 1], count });
                count = 1;
            }
        }
        p.push_back({ s[n - 1], count });

        vector<pair<char, int>> stk;
        int i = 0, np = p.size();

        for (int i = 0; i < p.size(); i++) {
            while (!stk.empty() && stk.back().first == '(' && p[i].first == ')'
                   && min(stk.back().second, p[i].second) >= k) {
                stk.back().second -= k;
                p[i].second -= k;
                if (stk.back().second == 0) stk.pop_back();
                if (!stk.empty() && stk.back().first == p[i].first) {
                    p[i].second += stk.back().second;
                    stk.pop_back();
                }
            }
            if (p[i].second == 0) continue;
            if (!stk.empty() && stk.back().first == p[i].first) {
                stk.back().second += p[i].second;
            } else {
                stk.push_back(p[i]);
            }
        }

        string ans = "";
        for (auto [ch, cnt]: stk) {
            while (cnt--) ans += ch;
        }
        return ans;
    }
};

// (((( )) ( )) (
// (,4 - ),2 - (,1 - ),2 - (,1
// (,4 <-- ),2
// (,2 <-- ),0
// (,2 <-- (,1