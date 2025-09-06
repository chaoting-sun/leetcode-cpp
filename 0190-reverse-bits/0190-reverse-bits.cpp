class Solution {
public:
    // Bit Manipulation

    int reverseBits(int n) {
        int ans = 0;
        int bits = 31;
        while (n > 0) {
            ans += (n & 1) << bits;
            n >>= 1;
            bits--;
        }
        return ans;
    }
};