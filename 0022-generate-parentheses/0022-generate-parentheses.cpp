class Solution {
public:
    void putParenthesis(int n_left, int n_right, stack<char>& st, string& s, vector<string>& ans) {
        // termination
        if (n_left == 0 && n_right == 0) {
            if (st.empty()) {
                ans.push_back(s);
            }
            return;
        }

        // put left parenthesis
        if (n_left) {
            string s_ = s;
            stack<char> st_ = st;
            s_ += '(';
            st_.push('(');
            putParenthesis(n_left - 1, n_right, st_, s_, ans);
        }
        
        // put right parenthesis
        if (n_right && !st.empty() && st.top() == '(') {
            string s_ = s;
            stack<char> st_ = st;
            s_ += ')';
            st_.pop();
            putParenthesis(n_left, n_right - 1, st_, s_, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        stack<char> st;
        string s = "";
        vector<string> ans;

        putParenthesis(n, n, st, s, ans);
        return ans;
    }
};