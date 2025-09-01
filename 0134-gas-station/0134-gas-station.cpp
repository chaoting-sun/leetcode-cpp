class Solution {
public:
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
