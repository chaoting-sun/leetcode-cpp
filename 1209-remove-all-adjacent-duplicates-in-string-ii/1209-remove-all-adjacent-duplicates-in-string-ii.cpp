class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for (int i = 0; i < s.size(); i++) {
            if (stk.size() > 0 && stk.back().first == s[i]) {
                stk.back().second++;
            } else {
                stk.push_back({ s[i], 1 });
            }
            if (stk.back().second >= k) stk.back().second -= k;
            if (stk.back().second == 0) stk.pop_back();
        }
        string ans;
        for (auto [c, count]: stk) {
            for (int i = 0; i < count; i++) ans += c;
        }
        return ans;
    }
};