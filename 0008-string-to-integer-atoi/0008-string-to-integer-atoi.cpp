class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if (n == 0) return 0;

        // leading whitespace
        int idx = 0;
        while (idx < n && s[idx] == ' ') idx++;
        if (idx == n) return 0;

        // the signedness
        int sign = 1;
        if (idx < n && (s[idx] == '+' || s[idx] == '-')) {
            if (s[idx] == '-') sign = -1;
            idx++;
        }
        // invalid condition
        if (idx == n || !isdigit(s[idx])) return 0;
        
        // compute the number
        int result = 0;
        while (idx < n && isdigit(s[idx])) {
            int digit = s[idx] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            idx++;
        }

        return sign * result;
    }
};

// Submit Error
// WA: val = val * 10 + s[idx];
// to
// val = val * 10 + (s[idx] - '0');