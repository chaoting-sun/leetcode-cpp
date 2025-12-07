class Solution {
public:
    int largestPrime(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[(int)j] = false;
                }
            }    
        }

        int ans = 0;
        int total_sum = 0;
        for (int i = 2; i <= n; i++) {
            if (!is_prime[i]) continue;

            total_sum += i;

            if (total_sum > n) break;
            if (is_prime[total_sum]) {
                ans = total_sum;
            }
        }

        return ans;
    }
};

// n = 1
// is_prime = [F, F]
// n = 2
// is_prime = [F, F, T]
// n = 3
// is_prime = [F, F, T, T]
// n = 8 -> 2 3
//             0  1  2  3  4  5  6  7
// is_prime = [F, F, T, T, F, T, F, T]