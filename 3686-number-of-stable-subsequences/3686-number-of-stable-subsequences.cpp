int MOD = 1e9 + 7;

class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        return countStableKSubsequences(nums, 3);
    }

    int countStableKSubsequences(vector<int>& nums, int k) {
        if (k <= 1) return 0; // 邊界情況：不能連續1個相同，等於什麼都不能選
        
        int MOD = 1e9 + 7;
        
        // dp[parity][len]
        // parity: 0 (even), 1 (odd)
        // len: 1 到 k-1 (因為不能達到 k)
        // 為了方便 index 操作，我們開大小為 k，只使用 index 1 到 k-1
        vector<vector<long long>> dp(2, vector<long long>(k, 0));
        
        for (int x : nums) {
            int p = (x % 2 == 0) ? 0 : 1; // 當前數字的奇偶性 (current parity)
            int q = 1 - p;                // 另一種奇偶性 (opposite parity)
            
            // 1. 計算所有「另一種奇偶性」結尾的子序列總和
            // 這些序列接上 x 後，會變成長度為 1 的新序列
            long long sum_opposite = 0;
            for (int len = 1; len < k; len++) {
                sum_opposite = (sum_opposite + dp[q][len]) % MOD;
            }
            
            // 2. 處理「同奇偶性」的延伸 (Extension)
            // 關鍵：從 k-1 倒數回到 2
            // dp[p][len] (新) = dp[p][len] (舊，不選x) + dp[p][len-1] (舊，選x接在後面)
            for (int len = k - 1; len >= 2; len--) {
                dp[p][len] = (dp[p][len] + dp[p][len-1]) % MOD;
            }
            
            // 3. 處理「長度為 1」的情況 (Start / Switch)
            // 來源：
            // (a) 舊的 dp[p][1] (不選 x)
            // (b) 數字 x 自己 (1)
            // (c) 接在對面奇偶性後面 (sum_opposite)
            dp[p][1] = (dp[p][1] + 1 + sum_opposite) % MOD;
        }
        
        // 4. 加總所有合法狀態
        long long total = 0;
        for (int p = 0; p <= 1; p++) {
            for (int len = 1; len < k; len++) {
                total = (total + dp[p][len]) % MOD;
            }
        }
        
        return (int)total;
    }
};

// k = 4
// 000, 00, 0, 111, 11, 1
// even -> update 0, 00, 000
// odd -> update 1, 11, 111

// class Solution {
// public:
//     int countStableSubsequences(vector<int>& nums) {
//         int n = nums.size();

//         vector<vector<long long>> dp(2, vector<long long>(2, 0));
//         int even = 0, odd = 1;
//         int one = 0, two = 1;
        
//         for (int i = 0; i < n; i++) {
//             int isEven = nums[i] % 2 == 0;

//             vector<vector<long long>> prevDP = dp;

//             if (isEven) {
//                 dp[even][one] = (1 + prevDP[even][one] + prevDP[odd][one] + prevDP[odd][two]) % MOD;
//                 dp[even][two] = (prevDP[even][two] + prevDP[even][one]) % MOD;
//             } else {
//                 dp[odd][one] = (1 + prevDP[even][one] + prevDP[odd][one] + prevDP[even][two]) % MOD;
//                 dp[odd][two] = (prevDP[odd][two] + prevDP[odd][one]) % MOD;
//             }
//             prevDP = dp;
//         }
//         long long total = 0;
//         for (int i = 0; i < 2; i++) {
//             for (int j = 0; j < 2; j++) total += dp[i][j];
//         }
//         return (int)(total % MOD);
//     }
// };

//    1 3 2
// 0  0 0 1
// 1  1 1 1
// 00 0 0 0
// 01 0 0 0
// 10 0 0 3
// 11 0 1 1

// 00 0 -> 0
// 01 0 -> 10
// 10 0 -> 00
// 11 0 -> 10

// 00 1 -> 01
// 01 1 -> 11
// 10 1 -> 01
// 11 1 -> 1