const int MOD = 1e9 + 7;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        if (n <= 2) return 0;

        sort(arr.begin(), arr.end());

        long long count = 0;
        for (int i = 0; i < n; i++) {
            int currentTarget = target - arr[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                int currentSum = arr[l] + arr[r];
                if (currentSum > currentTarget) {
                    r--;
                } else if (currentSum < currentTarget) {
                    l++;
                } else {
                    if (arr[l] == arr[r]) {
                        int length = r - l + 1;
                        count += length * (length - 1) / 2;
                        count %= MOD;
                        break;
                    } else {
                        int lcnt = 1, rcnt = 1;
                        while (l + 1 < r && arr[l] == arr[l + 1]) {
                            lcnt++;
                            l++;
                        }
                        while (l < r - 1 && arr[r - 1] == arr[r]) {
                            rcnt++;
                            r--;
                        }
                        count += lcnt * rcnt;
                        count %= MOD;
                        l++;
                        r--;
                    }
                }
            }
        }

        return (int)count;
    }
};