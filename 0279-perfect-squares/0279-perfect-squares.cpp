class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }
        for (int i = 1; i <= n; i++) {
            for (int sq: squares) {
                if (i >= sq) {
                    dp[i] = min(dp[i - sq] + 1, dp[i]);
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     int numSquares(int n) {
//         queue<int> q;
//         q.push(0);
//         int level = 0;
//         while (!q.empty()) {
//             int sz = q.size();
//             level++;
//             while (sz--) {
//                 int curr = q.front();
//                 q.pop();
//                 int left = n - curr;
//                 for (int i = 1; i * i <= left; i++) {
//                     int squared = i * i;
//                     if (squared == left) return level;
//                     q.push(curr + squared);
//                 }
//             }
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int numSquares(int n) {
//         queue<pair<int,int>> q;
//         q.push({ 0, 1 });
//         int level = 0;
//         while (!q.empty()) {
//             int sz = q.size();
//             level++;
//             while (sz--) {
//                 auto [curr, last] = q.front();
//                 q.pop();
//                 int left = n - curr;
//                 for (int i = last; i * i <= left; i++) {
//                     int squared = i * i;
//                     if (squared == left) return level;
//                     q.push({ curr + squared, i });
//                 }
//             }
//         }
//         return -1;
//     }
// };