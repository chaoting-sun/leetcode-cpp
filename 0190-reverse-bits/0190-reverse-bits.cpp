// class Solution {
// public:
//     // Bit Manipulation

//     int reverseBits(int n) {
//         int ans = 0;
//         int bits = 31;
//         while (n > 0) {
//             ans += (n & 1) << bits;
//             n >>= 1;
//             bits--;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    // Bit Manipulation

    int reverseBits(int n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }
        return ans;
    }
};