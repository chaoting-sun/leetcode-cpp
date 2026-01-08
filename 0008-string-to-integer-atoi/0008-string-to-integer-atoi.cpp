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
        long long val = 0;
        while (idx < n && isdigit(s[idx])) {
            val = val * 10 + (s[idx] - '0');
            // round the integer to remain in the range
            long long current_result = sign * val;
            if (current_result > INT_MAX) return INT_MAX;
            else if (current_result < INT_MIN) return INT_MIN;
            idx++;
        }

        return (int)(sign * val);
    }
};