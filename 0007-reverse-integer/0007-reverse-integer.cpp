class Solution {
public:
    // [2^31, 2^31 - 1] = [-2147483648, 2147483647]

    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10; // negative if x < 0
            x /= 10;

            // check upper bound
            // rev should be not larger than 214748364 to avoid overflow
            // if it is equal to 214748364, then the pop should be less than or equal to 7
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            // check lower bound
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};