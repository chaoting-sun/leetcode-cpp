class Solution {
public:
    // Problem: Return the length of the longest valid (well-formed) parentheses substring.
    //
    // Idea:
    // Use a stack of indices. Scan s left→right:
    //  - If we see a matching pair "()", pop the matching '(' index.
    //  - Otherwise, push the current index.
    //
    // After the scan, the stack contains indices of *unmatched* parentheses.
    // These indices partition the string into disjoint segments where every
    // valid substring must lie entirely within a segment. The answer is the
    // maximum distance between consecutive unmatched indices (treating the
    // string ends as virtual boundaries).
    
    // Time: O(n)
    // Space: O(n)

    int longestValidParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < (int)s.size(); i++) { // O(n)
            if (!stk.empty() && s[stk.top()] == '(' && s[i] == ')') {
                stk.pop();
            } else {
                stk.push(i);
            }
        }
        
        int maxLength = 0;
        int rightBound = s.size();
        while (!stk.empty()) { // O(n)
            maxLength = max(maxLength, rightBound - stk.top() - 1);
            rightBound = stk.top();
            stk.pop();
        }
        maxLength = max(maxLength, rightBound);

        return maxLength;
    }
};