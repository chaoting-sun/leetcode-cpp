class Solution {
public:
    // Approach: Stack
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> ops { "+", "-", "*", "/" };

        for (int i = 0; i < tokens.size(); i++) {
            if (ops.count(tokens[i])) {
                int digit_second = st.top();
                st.pop();
                int digit_first = st.top();
                st.pop();

                if (tokens[i] == "+") st.push(digit_first + digit_second);
                if (tokens[i] == "-") st.push(digit_first - digit_second);
                if (tokens[i] == "/") st.push(digit_first / digit_second);
                if (tokens[i] == "*") st.push(digit_first * digit_second);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};