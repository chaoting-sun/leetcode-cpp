class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{' || stk.empty()) {
                stk.push(s[i]);
            } else {
                if (stk.top() == '(' && s[i] == ')') stk.pop();
                else if (stk.top() == '[' && s[i] == ']') stk.pop();
                else if (stk.top() == '{' && s[i] == '}') stk.pop();
                else stk.push(s[i]);
            }
        }
        return stk.empty(); 
    }
};





// class Solution {
// public:
//     // Approach: Stack. use Stack to store the "(", "[", and "{" and pop them
//     // if get their pair
//     // Time: O(n)
//     // Space: O(n)

//     bool isValid(string s) {
//         stack<int> st;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
//                 st.push(s[i]);
//             } else {
//                 if (st.size() == 0) return false;
//                 if (!(st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']' || st.top() == '{' && s[i] == '}'))
//                     return false;
//                 st.pop();
//             }
//         }

//         return st.size() == 0;
//     }
// };