// Approach:
// 2 * x + 3y = n

// class Solution {
// public:
//     int getOperationNumber(int val) {
//         int multiplier = val / 2;
//         for (int i = 0; i <= multiplier; i++) {
//             int v = val - i * 2;
//             if (v % 3 == 0) {
//                 return i + v / 3;
//             }
//         }
//         return -1;
//     }
    
//     int minOperations(vector<int>& nums) {
//         unordered_map<int,int> counts;
//         for (int n: nums) counts[n]++;
//         int totalOps = 0;
//         for (auto [_, cnt]: counts) {
//             int ops = getOperationNumber(cnt);
//             if (ops == -1) return -1;
//             totalOps += ops;
//         }
//         return totalOps;
//     }
// };

// Approach:
// if cnt % 3 == 2 -> delete 2 first
// if cnt % 3 == 1 -> delete 4 first

class Solution {
public:    
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> counts;
        for (int n: nums) counts[n]++;
        int totalOps = 0;
        for (auto [_, cnt]: counts) {
            if (cnt == 1) return -1;
            totalOps += cnt / 3;
            if (cnt % 3 > 0) totalOps++;
        }
        return totalOps;
    }
};