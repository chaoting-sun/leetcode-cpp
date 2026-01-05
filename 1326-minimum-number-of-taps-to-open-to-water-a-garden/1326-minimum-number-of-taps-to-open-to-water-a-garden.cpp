// class Solution {
// public:
//     int minTaps(int n, vector<int>& ranges) {
//         vector<int> max_reach(n + 1);
//         for (int i = 0; i <= n; i++) {
//             int start = max(0, i - ranges[i]);
//             int end = min(n, i + ranges[i]);
//             max_reach[start] = end;
//         }

//         int tap_count = 0;
//         int current_end = 0;
//         int next_end = 0;
        
//         for (int i = 0; i < n; i++) {
//             next_end = max(next_end, max_reach[i]);
//             if (i == current_end) {
//                 if (next_end <= i) return -1;
//                 tap_count++;
//                 current_end = next_end;
//             }
//         }

//         return (current_end >= n) ? tap_count : -1;
//     }
// };

// #include <vector>
// #include <algorithm>

class Solution {
public:
    int minTaps(int n, std::vector<int>& ranges) {
        // "jumps[i]" stores the max index reachable from any tap covering index i
        std::vector<int> max_reach(n + 1, 0);

        // Preprocess: O(N) - Flatten intervals into a reach map
        for (int i = 0; i <= n; ++i) {
            int start = std::max(0, i - ranges[i]);
            int end = std::min(n, i + ranges[i]);
            max_reach[start] = std::max(max_reach[start], end);
        }

        // Greedy Walk: O(N)
        int taps = 0;
        int current_end = 0;
        int next_end = 0;

        for (int i = 0; i < n; ++i) { 
            next_end = std::max(next_end, max_reach[i]);

            if (i == current_end) {
                if (next_end <= i) return -1; // Gap detected
                taps++;
                current_end = next_end;
            }
        }

        return (current_end >= n) ? taps : -1;
    }
};