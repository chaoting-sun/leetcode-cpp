class Solution {
public:
    inline long long getKey(int xor_value, int balance_value) {
        return ((long long)xor_value << 32) | (unsigned int)balance_value;
    }

    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // 記錄狀態對應到的最早索引位置
        // Key: {current_xor, current_balance}
        // Value: index
        unordered_map<long long, int> first_occurrence;
        
        // Base case: 在索引 -1 的位置，XOR 為 0，奇偶平衡為 0
        first_occurrence[getKey(0, 0)] = -1;
        
        int curr_xor = 0;
        int curr_balance = 0;
        int max_len = 0;
        
        for (int i = 0; i < n; ++i) {
            // 更新 XOR 狀態
            curr_xor ^= nums[i];
            
            // 更新奇偶平衡狀態 (奇數 +1, 偶數 -1)
            curr_balance += (nums[i] % 2 != 0 ? 1 : -1);
            
            long long key = getKey(curr_xor, curr_balance);
            
            // 如果這個狀態曾經出現過，計算長度並更新最大值
            if (first_occurrence.count(key)) {
                max_len = max(max_len, i - first_occurrence[key]);
            } else {
                // 否則，記錄這個狀態第一次出現的位置
                first_occurrence[key] = i;
            }
        }
        
        return max_len;
    }
};