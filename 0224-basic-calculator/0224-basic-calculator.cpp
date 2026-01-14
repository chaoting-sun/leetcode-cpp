class Solution {
public:
    int calculate(string s) {
        stack<int> stk;

        int sign = 1;
        int operand = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                operand = operand * 10 + sign * (s[i] - '0');
            } else if (s[i] == '+') {
                ans += operand;
                sign = 1;
                operand = 0;
            } else if (s[i] == '-') {
                ans += operand;
                sign = -1;
                operand = 0;
            } else if (s[i] == '(') {
                // save the snapshot
                stk.push(ans);
                stk.push(sign);
                // reset
                ans = 0;
                operand = 0;
                sign = 1;
            } else if (s[i] == ')') {
                int currentAns = ans + operand;
                int prevSign = stk.top(); stk.pop();
                int prevAns = stk.top(); stk.pop();
                ans = prevAns + prevSign * currentAns;
                operand = 0;
            }
        }

        ans += operand;

        return ans;
    }
};
