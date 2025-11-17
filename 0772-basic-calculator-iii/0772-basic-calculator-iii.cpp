class Solution {
public:
    int calculate(string s) {
        int i = 0;
        int ans = eval(s, i);
        return ans;
    }

    int eval(string& s, int& i) {
        char sign = '+';
        int operand = 0;
        stack<int> stk;

        while (i < s.size()) {
            int ch = s[i];

            if (isdigit(ch)) {
                operand = operand * 10 + (ch - '0');
            }
            if (ch == '(') {
                i++;
                operand = eval(s, i);
                ch = s[i];
            }
            if ((!isdigit(ch) && !isspace(ch)) || i == s.size() - 1) {
                if (sign == '+') {
                    stk.push(operand);
                } else if (sign == '-') {
                    stk.push(-1 * operand);
                } else if (sign == '*') {
                    stk.top() = stk.top() * operand;
                } else if (sign == '/') {
                    stk.top() = stk.top() / operand;
                }
                operand = 0;
                sign = ch;

                if (sign == ')') {
                    i++;
                    break;
                }
            }
            i++;
        }

        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};