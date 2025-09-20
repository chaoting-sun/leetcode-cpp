class Solution {
public:
    // Approach 1.1: Recursive generation using a stack to track parentheses validity.
    // For each step, we can add '(' if we have open parentheses remaining, or ')' if there is a matching '(' on the stack.
    // When adding ')', we pop the matching '(' from the stack. Only when both open and right counts are zero and the stack is empty do we add a valid result.
    // This ensures all added strings are valid and well-formed.    // Time: O(2^n). We recursively generate all combinations by putting '(' or ')' for each run.
    
    // Time: O(Cn * n)
    // Let's start from the case that all possibilities are valid.
    // The final string will be of length 2n.
    // In each recursion we copy the string (takes O(n) in worst case), and push back to ans (takes O(n)) -> O(n)
    // Each recursion calls itself twice, so there are O(2^n) function calls
    // So, the time complexity is O(n*2^n)
    // However, in this question, the valid ans is much fewer than all possibilities. We will skip all that are invalid.
    // The number of such valid combinations is call the Catalan number for n, written as Cn.
    // Cn ~ 4^n / n^1.5
    // So the total time complexity is # valid results * work per result = Cn * O(n)
    
    // Space: O(n^2) used by recursion; O(Cn * 2n) used by ans
    // O(n^2) - recursion depth * max size of each recursion = O(n) * O(n) = O(n^2)

    // void putParenthesis(int n_open, int n_close, stack<char>& st, string& s, vector<string>& ans) {
    //     // termination
    //     if (n_open == 0 && n_close == 0) {
    //         if (st.empty()) {
    //             ans.push_back(s);
    //         }
    //         return;
    //     }

    //     // put open parenthesis
    //     if (n_open) {
    //         string s_ = s;
    //         stack<char> st_ = st;
    //         s_ += '(';
    //         st_.push('(');
    //         putParenthesis(n_open - 1, n_close, st_, s_, ans);
    //     }
        
    //     // put right parenthesis
    //     if (n_close && !st.empty() && st.top() == '(') {
    //         string s_ = s;
    //         stack<char> st_ = st;
    //         s_ += ')';
    //         st_.pop();
    //         putParenthesis(n_open, n_close - 1, st_, s_, ans);
    //     }
    // }

    // vector<string> generateParenthesis(int n) {
    //     stack<char> st;
    //     string s = "";
    //     vector<string> ans;

    //     putParenthesis(n, n, st, s, ans);
    //     return ans;
    // }

    // Approach1.2: Optimized -> for a valid parantheses, the number of open parentheses is always more than that of close parenthesis
    // Time: O(Cn * n)
    // Space: O(n^2)

    // void putParenthesis(int n_open, int n_close, string s, vector<string>& ans) {
    //     // termination
    //     if (n_open == 0 && n_close == 0) {
    //         ans.push_back(s);
    //         return;
    //     }

    //     // put open parenthesis
    //     if (n_open) {
    //         putParenthesis(n_open - 1, n_close, s + '(', ans);
    //     }
        
    //     // put close parenthesis
    //     if (n_close > n_open) {
    //         putParenthesis(n_open, n_close - 1, s + ')', ans);
    //     }
    // }

    // vector<string> generateParenthesis(int n) {
    //     string s = "";
    //     vector<string> ans;

    //     putParenthesis(n, n, s, ans);
    //     return ans;
    // }



    
    vector<string> ans;
    
    void backtrack(int nLeft, int nRight, int n, string& currentForm) {
        // invalid condition
        if (nLeft > n || nRight > n) return;
        // base case
        if (nLeft == n && nRight == n) {
            ans.push_back(currentForm);
            return;
        }

        if (nLeft < n) {
            currentForm.push_back('(');
            backtrack(nLeft + 1, nRight, n, currentForm);
            currentForm.pop_back();
        }
        if (nLeft > nRight) {
            currentForm.push_back(')');
            backtrack(nLeft, nRight + 1, n, currentForm);
            currentForm.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string currentForm;
        backtrack(0, 0, n, currentForm);
        return ans;
    }
};