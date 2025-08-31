class Solution {
public:
    // Approach: recursion, binary exponentiation
    // if n = even -> x^n = (x^(n/2))^2
    // if n = odd -> x^n = x * (x^((n-1)/2))
    // Time: O(logn)
    // Space: O(logn)

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
