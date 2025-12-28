// class Solution {
// public:
//     int smallestRepunitDivByK(int k) {
//         int n = 0;
//         int count = 0;

//         while (n < k) {
//             n = n * 10 + 1;
//             count++;
//         }

//         vector<bool> seen(k + 1, false);

//         while (true) {
//             n = n % k;
//             if (n == 0) return count;
            
//             if (seen[n]) break;
//             seen[n] = true;
            
//             n = n * 10 + 1;
//             count++;
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // optimization
        if (k % 2 == 0 || k % 5 == 0) return -1;
        
        int n = 0;
        for (int length = 1; length <= k; length++) {
            n = (n * 10 + 1) % k;
            if (n == 0) {
                return length;
            }
        }

        return -1;
    }
};