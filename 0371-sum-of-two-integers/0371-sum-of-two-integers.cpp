class Solution {
public:
    // Approach: Bit Manipulation
    // When adding two numbers in binary form, if we ignore the carry:
    // - If the two bits are different (one is 0, the other is 1), the sum bit is 1.
    // - Otherwise the sum bit is 0. This can be obtained using a XOR b.
    //
    // But if both bits are 1, we need to account for a carry.
    // The carry can be obtained with (a & b) << 1.
    //
    // Adding these two results gives the intermediate sum.
    // However, this new sum might still generate a carry,
    // so we repeat the process until the carry becomes 0.

    int getSum(int a, int b) {
        while (b != 0) {
            int tmp = (a & b) << 1;
            a = a ^ b;
            b = tmp;
        }
        return a;
    }
};

// -2 + 3 (4 bits)

// 2 -> 0010, -2 -> 1110
// 3 -> 0011

//    1110
//    0011
// a= 1101
// b= 0100

//    1101
//    0100
// a= 1001
// b= 1000

//    1001
//    1000
// a= 0001 -> 1
// b=10000 -> cut to 0000