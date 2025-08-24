class Solution {
public:
    // int gcdOfOddEvenSums(int n) {
    //     int odd_sum = 0, even_sum = 0;

    //     for (int i = 1; i <= 2*n; i++) {
    //         if (i % 2 == 1) {
    //             odd_sum += i;
    //         } else {
    //             even_sum += i;
    //         }
    //     }
    
    //     for (int i = min(odd_sum, even_sum); i >= 1; i--) {
    //         if (odd_sum % i == 0 && even_sum % i == 0) {
    //             return i;
    //         }
    //     }

    //     return 1;
    // }

    // the sum of first n odd numbers:
    // S = 1 + 3 + 5 + ... + (2n - 1)
    //   = n / 2 * (1 + (2n - 1)) = n^2
    // the sume of first n even numbers:
    // S = 2 + 4 + 6 + ... + 2n
    //   = 2 * (1 + n) * n / 2 = n (n + 1)
    // gcd(n^2, n(n+1)) = n

    int gcdOfOddEvenSums(int n) {
        return n;
    }
};

