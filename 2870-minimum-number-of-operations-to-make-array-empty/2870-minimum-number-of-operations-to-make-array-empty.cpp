class Solution {
public:
    int getOperationNumber(int val) {
        int multiplier = val / 2;
        for (int i = 0; i <= multiplier; i++) {
            int v = val - i * 2;
            if (v % 3 == 0) {
                return i + v / 3;
            }
        }
        return -1;
    }
    
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> counts;
        for (int n: nums) counts[n]++;
        int totalOpNumber = 0;
        for (auto [_, cnt]: counts) {
            int opNumber = getOperationNumber(cnt);
            if (opNumber == -1) return -1;
            totalOpNumber += opNumber;
        }
        return totalOpNumber;
    }
};

// 2 * x + 3y = n

// x = 0, y = n / 3
// x = n / 2, y = 0

