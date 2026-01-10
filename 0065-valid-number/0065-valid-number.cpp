// class Solution {
// public:
//     bool isNumber(string s) {
//         int n = s.size();
//         int idx = 0;

//         // check sign
//         if (s[idx] == '+' || s[idx] == '-') {
//             idx++;
//         }
        
//         bool seen_dot = false;
//         bool seen_digit = false;
//         while (idx < n && (s[idx] == '.' || isdigit(s[idx]))) {
//             if (s[idx] == '.') {
//                 // ex: "..", "12.1."
//                 if (seen_dot) return false;
//                 seen_dot = true;
//             } else {
//                 seen_digit = true;
//             }
//             idx++;
//         }

//         // ex: ".", "+."
//         if (!seen_digit) return false;

//         // ex: "12."
//         if (idx == n) return true;

//         // check exponential
//         bool has_e = false;
//         if (idx < n && (s[idx] == 'e' || s[idx] == 'E')) {
//             has_e = true;
//             idx++;
//         }

//         // ex: "12."
//         if (has_e) {
//             if (idx < n && (s[idx] == '+' || s[idx] == '-')) {
//                 idx++;
//             }

//             bool has_digit = false;
//             while (idx < n) {
//                 if (!isdigit(s[idx])) return false;
//                 else has_digit = true;
//                 idx++;
//             }

//             return has_digit;
//         } else {
//             // ex: "12."
//             if (idx == n) return true;
//             // ex: "12.w"
//             else return false;
//         }
//     }
// };

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool seen_digit = false;
        bool seen_e = false;
        bool seen_dot = false;

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                seen_digit = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) {
                    return false;
                }
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!seen_digit || seen_e) {
                    return false;
                }
                seen_e = true;
                seen_digit = false; // 困難
            } else if (s[i] == '.') {
                if (seen_dot || seen_e) {
                    return false;
                }
                seen_dot = true;
            } else {
                return false;
            }
        }

        return seen_digit; // 困難
    }
};