class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) return 1 / binaryExp(x, -n);
        
        // even
        if (n % 2 == 0) {
            double halfPow = binaryExp(x, n / 2);
            return halfPow * halfPow;
        }
        // odd
        else {
            double halfPow = binaryExp(x, (n - 1) / 2);
            return x * halfPow * halfPow;
        }
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long)n);
    }
};

// x = 2.1, n = 3
// odd -> halfPow = myPow(2.1, 1) -> 2.1 * myPow(2.1, 1) * myPow(2.1, 1)

// myPow(2.1, 1) -> odd -> halfPow = myPow(2.1, 0) = x