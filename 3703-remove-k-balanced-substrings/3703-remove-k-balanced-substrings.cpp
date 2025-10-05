class Solution {
public:
    // Approach: keeps removing the pattern in every run
    // Time: O(kn)
    // Space: O(1)
    // string removeSubstring(string s, int k) {
    //     string ans;

    //     for (char ch: s) {
    //         ans.push_back(ch);
    //         int n = ans.size();
    //         if (n >= 2 * k) {
    //             bool hasPattern = true;
    //             int right = n - k;
    //             int left = right - 1;
    //             for (int i = 0; i < k; i++) {
    //                 if (ans[left - i] != '(' || ans[right + i] != ')') {
    //                     hasPattern = false;
    //                     break;
    //                 }
    //             }
    //             if (hasPattern) {
    //                 ans.resize(n - 2 * k);
    //             }
    //         }
    //     }

    //     return ans;
    // }

    // Approach: keeps removing the pattern in every run
    // Time: O(n)
    // Space: O(1)
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> stk;

        for (char ch: s) {
            if (!stk.empty() && stk.back().first == ch) {
                stk.back().second++;
            } else {
                stk.push_back({ ch, 1 });
            }

            int n = stk.size();
            if (n >= 2 &&
                stk[n - 2].first == '(' &&
                stk[n - 2].second >= k &&
                stk[n - 1].first == ')' &&
                stk[n - 1].second >= k) {
                stk[n - 2].second -= k;
                stk[n - 1].second -= k;

                pair<char, int> last = stk.back();
                stk.pop_back();
                if (stk.back().second == 0) stk.pop_back();
                if (last.second > 0) stk.push_back(last);
                
                n = stk.size();
                if (n >= 2 && stk[n - 2].first == stk[n - 1].first) {
                    char lastCh = stk[n - 2].first;
                    int count = stk[n - 2].second + stk[n - 1].second;
                    stk.pop_back();
                    stk.pop_back();
                    stk.push_back({ lastCh, count });
                }
            }
        }

        string ans = "";
        for (int i = 0; i < stk.size(); i++) {
            for (int j = 0; j < stk[i].second; j++) {
                ans += stk[i].first;
            }
        }
        return ans;
    }
};

