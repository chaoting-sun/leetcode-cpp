class Solution {
public:
    // Approach: Greedy
    //
    // Step 1: Compute gain[i] = gas[i] - cost[i].
    //         - If gain[i] < 0, traveling from station i to i+1 consumes more gas than we get.
    //
    // Step 2: We want to find a starting station such that the cumulative sum of gains
    //         never drops below 0 while completing a full circle.
    //
    // Key Proof:
    //   Suppose we start from index `start` and fail at station `i` (current_gain < 0 at i).
    //   Then for any station k in [start, i], k cannot be a valid start.
    //
    //   Why? Because:
    //       gain(start..i) = gain(start..k-1) + gain(k..i).
    //       If gain(start..i) < 0 and gain(k..i) >= 0,
    //       then necessarily gain(start..k-1) < 0.
    //       That means starting from `start` would already fail before reaching k,
    //       so k cannot be a valid candidate either.
    //
    //   Therefore, once we fail at i, we can safely skip all stations in [start..i]
    //   and set the next start candidate to i+1.
    //
    // Step 3: If the total sum of all gains is negative, it is impossible to complete the circuit.
    //         Otherwise, the last recorded `start` is the unique valid solution.
    //
    // Complexity:
    //   - Time: O(n)
    //   - Space: O(1)
    //

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gain = 0;
        int current_gain = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            int gain = gas[i] - cost[i];
            total_gain += gain;
            current_gain += gain;
            if (current_gain < 0) {
                current_gain = 0;
                start = i + 1;
            }
        }

        return total_gain < 0 ? -1 : start;
    }
};
