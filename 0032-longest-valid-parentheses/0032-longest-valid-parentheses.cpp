class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < (int)s.size(); i++) {
            if (!stk.empty() && s[stk.top()] == '(' && s[i] == ')') {
                stk.pop();
            } else {
                stk.push(i);
            }
        }
        
        int maxLength = 0;
        int rightBound = s.size();
        while (!stk.empty()) {
            maxLength = max(maxLength, rightBound - stk.top() - 1);
            rightBound = stk.top();
            stk.pop();
        }
        maxLength = max(maxLength, rightBound);

        return maxLength;
    }
};