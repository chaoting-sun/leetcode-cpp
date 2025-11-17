class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> operators { "+", "-", "*", "/" };
        for (string& token: tokens) {
            if (operators.count(token)) {
                int currentOperand = stk.top(); stk.pop();
                int previousOperand = stk.top(); stk.pop();
                if (token == "+") {
                    stk.push(previousOperand + currentOperand);
                } else if (token == "-") {
                    stk.push(previousOperand - currentOperand);
                } else if (token == "*") {
                    stk.push(previousOperand * currentOperand);
                } else if (token == "/") {
                    stk.push(previousOperand / currentOperand);
                }
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};