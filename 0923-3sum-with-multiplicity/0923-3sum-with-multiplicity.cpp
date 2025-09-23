const int MOD = 1e9 + 7;
using ll = long long;

class Solution {
public:
    // int threeSumMulti(vector<int>& arr, int target) {
    //     int n = arr.size();
    //     if (n <= 2) return 0;

    //     sort(arr.begin(), arr.end());

    //     long long count = 0;
    //     for (int i = 0; i < n; i++) {
    //         int currentTarget = target - arr[i];
    //         int l = i + 1, r = n - 1;
    //         while (l < r) {
    //             int currentSum = arr[l] + arr[r];
    //             if (currentSum > currentTarget) {
    //                 r--;
    //             } else if (currentSum < currentTarget) {
    //                 l++;
    //             } else {
    //                 if (arr[l] == arr[r]) {
    //                     int length = r - l + 1;
    //                     count += length * (length - 1) / 2;
    //                     count %= MOD;
    //                     break;
    //                 } else {
    //                     int lcnt = 1, rcnt = 1;
    //                     while (l + 1 < r && arr[l] == arr[l + 1]) {
    //                         lcnt++;
    //                         l++;
    //                     }
    //                     while (l < r - 1 && arr[r - 1] == arr[r]) {
    //                         rcnt++;
    //                         r--;
    //                     }
    //                     count += lcnt * rcnt;
    //                     count %= MOD;
    //                     l++;
    //                     r--;
    //                 }
    //             }
    //         }
    //     }

    //     return (int)count;
    // }

    // Approach:
    // 1. Since values in arr are guaranteed to be in [0, 100], we can precompute
    //    frequency counts freq[v] = how many times value v appears.
    // 2. We then iterate over possible value triples (v1, v2, v3) with v1 <= v2 <= v3
    //    and check if v1 + v2 + v3 == target. This avoids double-counting permutations.
    // 3. For each valid triple, add the number of index triples contributed by
    //    the frequencies using combinatorics:
    //      - Case A: v1 == v2 == v3
    //          -> Choose 3 from freq[v1] = C(freq[v1], 3) = n*(n-1)*(n-2)/6
    //      - Case B: v1 == v2 != v3
    //          -> Choose 2 from freq[v1], and 1 from freq[v3]:
    //             C(freq[v1], 2) * freq[v3]
    //      - Case C: v1 < v2 < v3
    //          -> One from each: freq[v1] * freq[v2] * freq[v3]
    // 4. We accumulate the result in a 64-bit variable (to prevent overflow),
    //    then take modulo 1e9+7 at each step.
    //
    // Complexity:
    // - Building freq: O(n), where n = arr.size().
    // - Iterating v1, v2, computing v3: O(101^2) = ~10^4, independent of n.
    // - Total: O(n + 100^2), very efficient.
    //
    // Notes:
    // - Always promote to long long before multiplication to avoid overflow.
    // - Apply % MOD only on the sum, not inside the combinatorial formulas.
    // - Enforcing v1 <= v2 <= v3 ensures each triple is counted exactly once.

    int threeSumMulti(vector<int>& arr, int target) {
        vector<int> freq(101);
        for (int val: arr) freq[val]++;
        ll ans = 0;

        for (int v1 = 0; v1 <= 100; v1++) {
            for (int v2 = 0; v2 <= 100; v2++) {
                int v3 = target - v1 - v2;
                if (v3 < 0 || v3 > 100) continue;

                ll c1 = freq[v1], c2 = freq[v2], c3 = freq[v3];

                if (v1 == v2 && v2 == v3) {
                    ll add = c1 * (c1 - 1) * (c1 - 2) / 6;
                    ans = (ans + add) % MOD;
                } else if (v1 == v2 && v2 != v3) {
                    ll add = c1 * (c1 - 1) / 2 * c3;
                    ans = (ans + add) % MOD;
                } else if (v1 < v2 && v2 < v3) {
                    ll add = c1 * c2 * c3;
                    ans = (ans + add) % MOD;
                }
            }
        }
        return (int)ans;
    }

    // For future practice

    // int threeSumMulti(vector<int>& arr, int target) {

    // }
};