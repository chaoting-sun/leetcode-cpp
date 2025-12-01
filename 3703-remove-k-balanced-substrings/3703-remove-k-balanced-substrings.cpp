// class Solution {
// public:
//     string removeSubstring(string s, int k) {
//         int n = s.size();
//         if (n == 0) return "";

//         vector<pair<char, int>> p;
//         int count = 1;
//         for (int i = 1; i < n; i++) {
//             if (s[i - 1] == s[i]) {
//                 count++;
//             } else {
//                 p.push_back({ s[i - 1], count });
//                 count = 1;
//             }
//         }
//         p.push_back({ s[n - 1], count });

//         vector<pair<char, int>> stk;
//         int i = 0, np = p.size();

//         for (int i = 0; i < p.size(); i++) {
//             while (!stk.empty() && stk.back().first == '(' && p[i].first == ')'
//                    && min(stk.back().second, p[i].second) >= k) {
//                 stk.back().second -= k;
//                 p[i].second -= k;
//                 if (stk.back().second == 0) stk.pop_back();
//                 if (!stk.empty() && stk.back().first == p[i].first) {
//                     p[i].second += stk.back().second;
//                     stk.pop_back();
//                 }
//             }
//             if (p[i].second == 0) continue;
//             if (!stk.empty() && stk.back().first == p[i].first) {
//                 stk.back().second += p[i].second;
//             } else {
//                 stk.push_back(p[i]);
//             }
//         }

//         string ans = "";
//         for (auto [ch, cnt]: stk) {
//             while (cnt--) ans += ch;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char,int>> runs; // {char, count} 代表連續 run

        for (char ch : s) {
            // 1) 推入：併到現有 run 或開新 run
            if (!runs.empty() && runs.back().first == ch) {
                runs.back().second++;
            } else {
                runs.push_back({ch, 1});
            }

            // 2) 嘗試移除尾端的 k-balanced："((" *k + "))" *k
            if (runs.size() >= 2) {
                auto &right = runs.back();
                auto &left  = runs[runs.size() - 2];

                if (right.first == ')' && left.first == '(' &&
                    right.second >= k && left.second >= k) {
                    // 各自減少 k
                    right.second -= k;
                    left.second  -= k;

                    // 若某段用盡，彈出
                    if (right.second == 0) runs.pop_back();
                    if (runs.back().second == 0) runs.pop_back(); // left 可能現在在頂端
                }
            }
        }

        // 3) 重建答案
        string ans;
        ans.reserve(s.size());
        for (auto &p : runs) ans.append(p.second, p.first);
        return ans;
    }
};