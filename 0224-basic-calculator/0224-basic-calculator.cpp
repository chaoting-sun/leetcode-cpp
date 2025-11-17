class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int sign = 1;
        int operand = 0;

        stack<int> stk;
        for (char ch: s) {
            if (isdigit(ch)) {
                operand = operand * 10 + (ch - '0');
            } else if (ch == '+') {
                ans += sign * operand;
                sign = 1;
                operand = 0;
            } else if (ch == '-') {
                ans += sign * operand;
                sign = -1;
                operand = 0;
            } else if (ch == '(') {
                stk.push(ans);
                stk.push(sign);
                
                ans = 0;
                sign = 1;
                operand = 0;
            } else if (ch == ')') {
                ans += sign * operand;
                int prevSign = stk.top(); stk.pop();
                int prevOperand = stk.top(); stk.pop();
                ans = prevOperand + prevSign * ans;
                
                operand = 0;
            }
        }
        ans += sign * operand;
        return ans;
    }
};






