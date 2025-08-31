class Solution {
public:
    int convert(int n) {
        int converted = 0;
        while (n > 0) {
            int remainder = n % 10;
            converted += remainder*remainder;
            n /= 10;
        }
        return converted;
    }

    bool isHappy(int n) {
        // store the visited digits that is less than 10
        unordered_set<int> visited;

        while (n != 1) {
            n = convert(n);
            if (n < 10) {
                if (visited.count(n)) {
                    return false;
                }
                visited.insert(n);
            }
        }

        return n == 1;
    }
};