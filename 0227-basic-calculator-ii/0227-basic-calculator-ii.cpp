class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char sign = '+';
        stack<int> stk;
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            if ((!isdigit(ch) && !iswspace(ch)) || i == s.size() - 1) {
                if (sign == '+') {
                    stk.push(num);
                } else if (sign == '-') {
                    stk.push((-1) * num);
                } else if (sign == '*') {
                    int prevNum = stk.top();
                    stk.pop();
                    stk.push(prevNum * num);
                } else {
                    int prevNum = stk.top();
                    stk.pop();
                    stk.push(prevNum / num);
                }
                num = 0;
                sign = ch;
            }
        }

        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};