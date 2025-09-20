class Solution {
public:
    // Approach: Stack
    // Time: O(n), the time to traverse all tokens
    // Space: O(n)
    // int evalRPN(vector<string>& tokens) {
    //     stack<int> st;
    //     unordered_set<string> ops { "+", "-", "*", "/" };

    //     for (int i = 0; i < tokens.size(); i++) {
    //         if (ops.count(tokens[i])) {
    //             int digit_second = st.top();
    //             st.pop();
    //             int digit_first = st.top();
    //             st.pop();

    //             if (tokens[i] == "+") st.push(digit_first + digit_second);
    //             if (tokens[i] == "-") st.push(digit_first - digit_second);
    //             if (tokens[i] == "/") st.push(digit_first / digit_second);
    //             if (tokens[i] == "*") st.push(digit_first * digit_second);
    //         } else {
    //             st.push(stoi(tokens[i]));
    //         }
    //     }
    //     return st.top();
    // }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string token: tokens) {
            if (isdigit(token.back())) {
                stk.push(stoi(token));
            } else {
                int latter = stk.top();
                stk.pop();
                int former = stk.top();
                stk.pop();

                if (token == "+") stk.push(former + latter);
                if (token == "-") stk.push(former - latter);
                if (token == "*") stk.push(former * latter);
                if (token == "/") stk.push(former / latter);
            }
        }
        return stk.top();
    }
};