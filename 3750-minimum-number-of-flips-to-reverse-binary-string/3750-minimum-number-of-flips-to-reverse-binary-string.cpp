class Solution {
public:
    int minimumFlips(int n) {
        int bitLength = 0;
        int tmp = n;
        while (tmp > 0) {
            tmp >>= 1;
            bitLength++;
        }
        int ans = 0;
        for (int i = 0; i < bitLength / 2; i++) {
            int bit1 = (n >> i) & 1;
            int bit2 = (n >> (bitLength - 1 - i)) & 1;
            if (bit1 != bit2) ans += 2;
        }
        return ans;
    }
};

