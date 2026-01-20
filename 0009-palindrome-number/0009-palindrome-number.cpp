// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;

//         vector<int> digits;
//         while (x > 0) {
//             digits.push_back(x % 10);
//             x /= 10;
//         }

//         int n = digits.size();
//         for (int i = 0; i < n / 2; i++) {
//             if (digits[i] != digits[n - 1 - i]) return false;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;

//         long long reversed = 0;
//         int y = x;
//         while (y > 0) {
//             reversed = reversed * 10 + y % 10;
//             y /= 10;
//         }

//         return reversed == (long long)x;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x > 0) return false;

        int reversed = 0;
        while (reversed < x) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return (x == reversed) || (x == reversed / 10);
    }
};