class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long m = abs((long long)n);
        while (m > 0) {
            if (m % 2 == 1) ans *= x;
            x *= x;
            m /= 2;
        }
        return n >= 0 ? ans : 1 / ans;
    }
};