class Solution {
public:
    int calculate(string s) {
        stack<pair<int,long long>> stk;

        int sign = 1;
        long long operand = 0;
        long long ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                operand = operand * 10 + (s[i] - '0');
            } else if (s[i] == '+') {
                ans += sign * operand;
                sign = 1;
                operand = 0;
            } else if (s[i] == '-') {
                ans += sign * operand;
                sign = -1;
                operand = 0;
            } else if (s[i] == '(') {
                // save the snapshot
                stk.push({ sign, ans });
                // reset
                ans = 0;
                operand = 0;
                sign = 1;
            } else if (s[i] == ')') {
                int currentAns = ans + sign * operand;
                auto [prevSign, prevAns] = stk.top();
                stk.pop();
                ans = prevAns + prevSign * currentAns;
                operand = 0;
            }
        }

        ans += sign * operand;

        return (int)ans;
    }
};
