class Solution {
public:
    // Approach: hash table to detect cycle

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
        // store the visited digits
        unordered_set<int> visited;

        while (n != 1) {
            n = convert(n);
            if (visited.count(n)) {
                return false;
            }
            visited.insert(n);
        }

        return n == 1;
    }
};