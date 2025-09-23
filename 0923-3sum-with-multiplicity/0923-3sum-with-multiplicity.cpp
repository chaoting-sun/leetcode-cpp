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

    int threeSumMulti(vector<int>& arr, int target) {
        vector<int> valueCount(101);
        for (int val: arr) valueCount[val]++;
        long long count = 0;
        for (int v1 = 0; v1 <= 100; v1++) {
            for (int v2 = 0; v2 <= 100; v2++) {
                int v3 = target - v1 - v2;
                if (v3 < 0 || v3 > 100) continue;
                if (v1 == v2 && v2 == v3) {
                    ll temp1 = (ll)valueCount[v1] * (valueCount[v1] - 1) % MOD;
                    ll temp2 = (ll)temp1 * (valueCount[v1] - 2) / 6 % MOD;
                    count += temp2;
                } else if (v1 == v2 && v2 != v3) {
                    count += (ll)(valueCount[v1] * (valueCount[v1] - 1) / 2 * valueCount[v3]);
                } else if (v1 < v2 && v2 < v3) {
                    count += (ll)(valueCount[v1] * valueCount[v2] * valueCount[v3]);
                }
                count %= MOD;
            }
        }
        return (int)count;
    }
};