class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int xBackup = x;
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        int res = xBackup % sum;
        return res == 0 ? sum : -1;
    }
};