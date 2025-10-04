class Solution {
public:
    // bool isThree(int n) {
    //     int divisors = 0;
    //     for (int i = 1; i <= n; i++) {
    //         if (n % i == 0) divisors++;
    //         if (divisors > 3) return false;
    //     }
    //     return divisors == 3;
    // }

    bool isThree(int n) {
        int divisors = 0;
        for (int d = 1; d <= (int)sqrt(n); d++) {
            if (n % d == 0) {
                divisors += 2;
                if (d * d == n) divisors--;
            }
            if (divisors > 3) return false;
        }
        return divisors == 3;
    }
};