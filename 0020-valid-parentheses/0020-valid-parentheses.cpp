class Solution {
public:
    // Approach: Stack. use Stack to store the "(", "[", and "{" and pop them
    // if get their pair

    bool isValid(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                 if (st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']' || st.top() == '{' && s[i] == '}') {
                    st.pop();
                 } else {
                    return false;
                 }
            }
        }

        return st.size() == 0;
    }
};