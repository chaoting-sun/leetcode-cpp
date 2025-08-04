class Solution {
public:
    // Intuition: for a car (A), to form a car fleet with the car (B) in front of it, it needs to
    // catch up B before B arrives at the target. That is, if A can pass B, then A takes less time
    // then B to arrive at the target. Therefore, we can firstly assume that each car can pass the
    // cars ahead, and compute the time they'll take. If a car A start from a larger position then
    // B, but B takes less time then A, then A and B will form a car fleet.
    
    // Approach: Array/Stack & Sort. compute the time a car will arrive at the target assuming that each car can pass
    // all the others, storing in the time array "time". Then sort "time" in reverse order of the
    // position. We loop through time from 0 to n - 1. For each new max. value, the corresponding
    // car form a car fleet.

    // Time: O(n*log(n)) -> sorting
    // Space: O(n)

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<double> time(n);

        for (int i = 0; i < n; i++) {
            time[i] = (target - position[i]) * 1.0 / speed[i];
        }
        
        vector<int> time_ids(n);
        for (int i = 0; i < n; i++) time_ids[i] = i;
        
        sort(time_ids.begin(), time_ids.end(), [&](int i, int j){
            return position[i] > position[j];
        });

        vector<double> sorted_time(n);
        for (int i = 0; i < n; i++) sorted_time[i] = time[time_ids[i]];


        // 1. find the number of larger values in the array
        // int n_car_fleets = 1;
        // double max_val = sorted_time[0];
        // for (int i = 1; i < n; i++) {
        //     if (sorted_time[i] > max_val) {
        //         max_val = sorted_time[i];
        //         n_car_fleets++;
        //     }
        // }
        // return n_car_fleets;

        // 2. put values in the stack
        stack<double> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || st.top() < sorted_time[i]) {
                st.push(sorted_time[i]);
            }
        }
        return st.size();
    }
};