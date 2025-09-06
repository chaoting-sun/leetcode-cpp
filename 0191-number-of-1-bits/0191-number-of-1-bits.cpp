class Solution {
public:
    // Approach: Bit Manipulation
    // AND: a & 1 = the bit of LSB

    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
};