class Solution {
public:
    int calculate(string s) {
        int currentNum = 0;
        char sign = '+';
        stack<int> stk;
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            }
            if ((!isdigit(ch) && !iswspace(ch)) || i == s.size() - 1) {
                if (sign == '+') {
                    stk.push(currentNum);
                } else if (sign == '-') {
                    stk.push((-1) * currentNum);
                } else if (sign == '*') {
                    int previousNum = stk.top();
                    stk.pop();
                    stk.push(previousNum * currentNum);
                } else {
                    int previousNum = stk.top();
                    stk.pop();
                    stk.push(previousNum / currentNum);
                }
                currentNum = 0;
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

// class Solution {
// public:
//     int calculate(string s) {
//         char sign = '+';
//         int ans = 0;
//         int lastNum = 0, num = 0;
        
//         for (int i = 0; i < s.size(); i++) {
//             char ch = s[i];
//             if (isdigit(ch)) {
//                 num = num * 10 + (ch - '0');
//             }
//             if ((!isdigit(ch) && !iswspace(ch)) || i == s.size() - 1) {
//                 if (sign == '+') {
//                     ans += lastNum;
//                     lastNum = num;
//                 } else if (sign == '-') {
//                     ans += lastNum;
//                     lastNum = -1 * num;
//                 } else if (sign == '*') {
//                     lastNum *= num;
//                 } else {
//                     lastNum /= num;
//                 }
//                 num = 0;
//                 sign = ch;
//             }
//         }
//         return ans;
//     }
// };