class Solution {
public:
    // Intuition: To form a car fleet, a car must catch up to the car in front before that car reaches the target. This only happens if the rear car takes less time to arrive than the one ahead.
    // So, we start by calculating the time each car would take to reach the target (as if there were no other cars in the way).
    // If a car is behind in position but takes longer or equal time, it can't catch up and will be part of a separate fleet.
    
    // Approach: Array/Stack & Sort. compute the time a car will arrive at the target assuming that each car can pass
    // all the others, storing in the time array "time". Then sort "time" in reverse order of the
    // position. We loop through time from 0 to n - 1. For each new max. value, the corresponding
    // car form a car fleet.

    // Approach:
    // 1. Compute the time each car takes to reach the target and pair it with its starting position.
    // 2. Sort the cars by starting position in descending order (from closest to farthest from the target).
    // 3. Iterate through the sorted list and group cars into fleets:
    //  - A car forms a new fleet if its time is greater than all times seen so far.
    //  - Otherwise, it merges into the current fleet (as it can't arrive earlier than the car ahead).
    // This way, each strictly increasing time in reverse position order indicates a new fleet.

    // Time: O(n*log(n)) -> sorting
    // Space: O(n)

    // int carFleet(int target, vector<int>& position, vector<int>& speed) {
    //     int n = position.size();
    //     vector<double> time(n);

    //     for (int i = 0; i < n; i++) {
    //         time[i] = (target - position[i]) * 1.0 / speed[i];
    //     }
        
    //     vector<int> time_ids(n);
    //     for (int i = 0; i < n; i++) time_ids[i] = i;
        
    //     sort(time_ids.begin(), time_ids.end(), [&](int i, int j){
    //         return position[i] > position[j];
    //     });

    //     vector<double> sorted_time(n);
    //     for (int i = 0; i < n; i++) sorted_time[i] = time[time_ids[i]];

    //     // 1. find the number of larger values in the array
    //     // int n_car_fleets = 1;
    //     // double max_val = sorted_time[0];
    //     // for (int i = 1; i < n; i++) {
    //     //     if (sorted_time[i] > max_val) {
    //     //         max_val = sorted_time[i];
    //     //         n_car_fleets++;
    //     //     }
    //     // }
    //     // return n_car_fleets;

    //     // 2. put values in the stack
    //     stack<double> st;
    //     for (int i = 0; i < n; i++) {
    //         if (st.empty() || st.top() < sorted_time[i]) {
    //             st.push(sorted_time[i]);
    //         }
    //     }
    //     return st.size();
    // }




    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return position[i] < position[j];
        });
        sort(position.begin(), position.end());
        vector<int> sortedSpeed(n);
        for (int i = 0; i < n; i++) sortedSpeed[i] = speed[idx[i]];

        vector<double> timeToArrive(n);
        for (int i = 0; i < n; i++) {
            timeToArrive[i] = (target - position[i]) * 1.0 / sortedSpeed[i];
        }

        int numFleets = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (timeToArrive[i - 1] > timeToArrive[i]) {
                numFleets++;
            }
        }

        numFleets += 1;
        return numFleets;
    }
};