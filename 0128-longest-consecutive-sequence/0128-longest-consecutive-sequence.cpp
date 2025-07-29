class Solution {
public:
    // Approach1: sort and check in sequential
    // Time: O(n*log(n)) -> sorting takes O(n*log(n))
    // Space: O(1)

    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;

    //     sort(nums.begin(), nums.end());
        
    //     int current = nums[0];
    //     int count = 1, max_count = 1;

    //     for (int i = 1; i < n; i++) {
    //         if (nums[i] == current) continue;

    //         if (nums[i] == current + 1) {
    //             count++;
    //         } else {
    //             max_count = max(max_count, count);
    //             count = 1;
    //         }
    //         current = nums[i];
    //     }
        
    //     return max(max_count, count);
    // }

    // Approach2: This solution uses a hash map to dynamically merge consecutive sequences
    // without sorting. For each number, it checks if adjacent numbers (n-1 and n+1) exist
    // to form or extend a sequence. The hash map stores only the lengths of sequences at
    // their leftmost and rightmost boundaries. When a number connects two sequences, their
    // lengths are combined, and the boundaries are updated to reflect the new total length.
    // Time: O(n), where n is the length of nums
    // Space: O(n)

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_map<int, int> seq_map;
        int max_len = 1;

        for (int n: nums) {
            if (seq_map.find(n) != seq_map.end()) continue;

            int n_seq = 1;
            int has_left_seq = seq_map.find(n - 1) != seq_map.end();
            int has_right_seq = seq_map.find(n + 1) != seq_map.end();

            if (has_left_seq) n_seq += seq_map[n - 1];
            if (has_right_seq) n_seq += seq_map[n + 1];

            if (has_left_seq) seq_map[n - seq_map[n - 1]] = n_seq;
            if (has_right_seq) seq_map[n + seq_map[n + 1]] = n_seq;
            seq_map[n] = n_seq;

            if (n_seq > max_len) {
                max_len = n_seq;
            }
        }

        return max_len;
    }
};
