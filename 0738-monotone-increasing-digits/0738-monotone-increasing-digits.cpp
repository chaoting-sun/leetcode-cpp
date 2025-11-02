class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int maxIdx = -1, maxVal = INT_MIN;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] > maxVal) {
                maxVal = s[i];
                maxIdx = i;
            }
            if (s[i] > s[i + 1]) {
                s[maxIdx]--;
                for (int j = maxIdx + 1; j < s.size(); j++) {
                    s[j] = '9';
                }
                break;
            }
        }
        return stoi(s);
    }
};




// class Solution {
// public:
//     int monotoneIncreasingDigits(int n) {
//         vector<int> digits;
//         while (n) {
//             digits.push_back(n % 10);
//             n /= 10;
//         }
//         reverse(digits.begin(), digits.end());
        
//         int m = digits.size();
//         vector<int> stk; // monotonic stack
//         for (int i = 0; i < m; i++) {
//             int nPopped = 0, lastPopped = 0;
//             while (!stk.empty() && stk.back() > digits[i]) {
//                 lastPopped = stk.back();
//                 stk.pop_back();
//                 nPopped++;
//             }
//             if (nPopped) {
//                 stk.push_back(lastPopped - 1);
//                 while (nPopped--) stk.push_back(9);
//             } else {
//                 stk.push_back(digits[i]);
//             }
//         }

//         int ans = 0;
//         for (int i = 0; i < m; i++) {
//             ans = ans * 10 + stk[i];
//         }
//         return ans;
//     }
// };