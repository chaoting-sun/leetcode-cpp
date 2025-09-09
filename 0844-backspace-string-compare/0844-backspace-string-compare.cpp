class Solution {
public:
    // Approach: Stack
    // Time: O(n)
    // Space: O(n)

    bool backspaceCompare(string s, string t) {
        stack<int> stk_s, stk_t;
        for (char c: s) {
            if (c == '#') {
                if (!stk_s.empty()) stk_s.pop();
            } else {
                stk_s.push(c);
            }
        }
        for (char c: t) {
            if (c == '#') {
                if (!stk_t.empty()) stk_t.pop();
            } else {
                stk_t.push(c);
            }
        }

        if (stk_s.size() != stk_t.size()) return false;
        while (!stk_s.empty() && !stk_t.empty()) {
            if (stk_s.top() != stk_t.top()) return false;
            stk_s.pop();
            stk_t.pop();
        }
        return true;
    }
};