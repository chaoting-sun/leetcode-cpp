// class Solution {
// public:
//     // Approach: keeps removing the pattern in every run
//     // Time: O(kn)
//     // Space: O(1)
//     // string removeSubstring(string s, int k) {
//     //     string ans;

//     //     for (char ch: s) {
//     //         ans.push_back(ch);
//     //         int n = ans.size();
//     //         if (n >= 2 * k) {
//     //             bool hasPattern = true;
//     //             int right = n - k;
//     //             int left = right - 1;
//     //             for (int i = 0; i < k; i++) {
//     //                 if (ans[left - i] != '(' || ans[right + i] != ')') {
//     //                     hasPattern = false;
//     //                     break;
//     //                 }
//     //             }
//     //             if (hasPattern) {
//     //                 ans.resize(n - 2 * k);
//     //             }
//     //         }
//     //     }

//     //     return ans;
//     // }

//     // Approach: keeps removing the pattern in every run
//     // Time: O(n)
//     // Space: O(1)
//     string removeSubstring(string s, int k) {
//         vector<pair<char, int>> stk;

//         for (char ch: s) {
//             if (!stk.empty() && stk.back().first == ch) {
//                 stk.back().second++;
//             } else {
//                 stk.push_back({ ch, 1 });
//             }

//             int n = stk.size();
//             if (n >= 2 &&
//                 stk[n - 2].first == '(' &&
//                 stk[n - 2].second >= k &&
//                 stk[n - 1].first == ')' &&
//                 stk[n - 1].second >= k) {
//                 stk[n - 2].second -= k;
//                 stk[n - 1].second -= k;

//                 pair<char, int> last = stk.back();
//                 stk.pop_back();
//                 if (stk.back().second == 0) stk.pop_back();
//                 if (last.second > 0) stk.push_back(last);
                
//                 n = stk.size();
//                 if (n >= 2 && stk[n - 2].first == stk[n - 1].first) {
//                     char lastCh = stk[n - 2].first;
//                     int count = stk[n - 2].second + stk[n - 1].second;
//                     stk.pop_back();
//                     stk.pop_back();
//                     stk.push_back({ lastCh, count });
//                 }
//             }
//         }

//         string ans = "";
//         for (int i = 0; i < stk.size(); i++) {
//             for (int j = 0; j < stk[i].second; j++) {
//                 ans += stk[i].first;
//             }
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
            while (runs.size() >= 2) {
                auto &right = runs.back();
                auto &left  = runs[runs.size() - 2];

                if (right.first == ')' && left.first == '(' &&
                    right.second >= k && left.second >= k) {
                    // 各自減少 k
                    right.second -= k;
                    left.second  -= k;

                    // 若某段用盡，彈出
                    if (right.second == 0) runs.pop_back();
                    if (!runs.empty() && runs.back().second == 0) runs.pop_back(); // left 可能現在在頂端

                    // 彈完後，若頂端兩段字元相同，合併（維持 run 的正規化）
                    if (runs.size() >= 2 && runs.back().first == runs[runs.size()-2].first) {
                        runs[runs.size()-2].second += runs.back().second;
                        runs.pop_back();
                    }
                    // 持續 while，看是否還能連鎖移除
                } else {
                    break;
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