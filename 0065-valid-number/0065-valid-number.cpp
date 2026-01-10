class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int idx = 0;

        // check sign
        if (s[idx] == '+' || s[idx] == '-') {
            idx++;
        }
        
        bool seen_dot = false;
        bool seen_digit = false;
        while (idx < n && (s[idx] == '.' || isdigit(s[idx]))) {
            if (s[idx] == '.') {
                // ex: "..", "12.1."
                if (seen_dot) return false;
                seen_dot = true;
            } else {
                seen_digit = true;
            }
            idx++;
        }

        // ex: ".", "+."
        if (!seen_digit) return false;

        // ex: "12."
        if (idx == n) return true;

        // check exponential
        bool has_e = false;
        if (idx < n && (s[idx] == 'e' || s[idx] == 'E')) {
            has_e = true;
            idx++;
        }

        // ex: "12."
        if (has_e) {
            if (idx < n && (s[idx] == '+' || s[idx] == '-')) {
                idx++;
            }

            bool has_digit = false;
            while (idx < n) {
                if (!isdigit(s[idx])) return false;
                else has_digit = true;
                idx++;
            }

            return has_digit;
        } else {
            if (idx == n) return true;
            else return false;
        }
    }
};

// 12e

// 12.(e4)

// 12.
// 1.12
// .12

// valid number
//  integer                  + (optional)exp
//   (optional)-/+ + digits
//  decimal                  + (optional)exp
//   (optional)-/+ + following
//                   digit + .
//                   digit + . + digit
//                   . + digit
// exp = e/E + interger
