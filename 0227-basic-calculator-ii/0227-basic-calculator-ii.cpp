class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int result = 0;
        int last_operand = 0;
        int operand = 0;
        char sign = '+';

        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == '+' || s[i] == '-' || s[i] ==  '*' || s[i] == '/') {
                if (sign == '+') {
                    result += last_operand;
                } else if (sign == '-') {
                    stk.push(-operand);
                } else if (sign == '*') {
                    stk.top() *= operand;
                } else {
                    stk.top() /= operand;
                }
                if (i < n) {
                    operand = 0;
                    sign = s[i];
                }
            } else if (isdigit(s[i])) {
                operand = operand * 10 + (s[i] - '0');
            }
        }
        
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top(); stk.pop();
        }
        return ans;
    }
};

// class Solution {
// public:
//     int calculate(string s) {
//         int n = s.size();
//         if (n == 0) return 0;

//         stack<int> stk;
//         int operand = 0;
//         char sign = '+';

//         for (int i = 0; i <= n; i++) {
//             if (i == n || s[i] == '+' || s[i] == '-' || s[i] ==  '*' || s[i] == '/') {
//                 if (sign == '+') {
//                     stk.push(operand);
//                 } else if (sign == '-') {
//                     stk.push(-operand);
//                 } else if (sign == '*') {
//                     stk.top() *= operand;
//                 } else {
//                     stk.top() /= operand;
//                 }
//                 if (i < n) {
//                     operand = 0;
//                     sign = s[i];
//                 }
//             } else if (isdigit(s[i])) {
//                 operand = operand * 10 + (s[i] - '0');
//             }
//         }
        
//         int ans = 0;
//         while (!stk.empty()) {
//             ans += stk.top(); stk.pop();
//         }
//         return ans;
//     }
// };

// test case: s = "3+2*2"
//                 012345
//                      i
// trace:
// i = 0: operand = 3
// i = 1: stk = [3], operand = 0, sign = +
// i = 2: operand = 2
// i = 3: stk = [3,2], operand = 0, sign = *
// i = 4: operand = 2
// i = 5: stk = [3, 4]
// ans = 7

// test case: s = "-1" = -1
// trace:
// i = 0: stk = [0], operator = -
// i = 1: operand = 1
// i = 2: stk = [0, -1]
// ans = 0 - 1 = -1

// test case: s = "12-2*4+1" = 5
//                 01234567
//                         i
// i = 0: operand = 1
// i = 1: operand = 12
// i = 2: stk = [12], operand = 0, operator = -
// i = 3: operand = 2
// i = 4: stk = [12, -2], operand = 0, operator = *
// i = 5: operand = 4
// i = 6: stk = [12, -8], operand = 0, operator = +
// i = 7: operand = 1
// i = 8: stk = [12, -8, 1]
// ans = 12 - 8 + 1 = 5
