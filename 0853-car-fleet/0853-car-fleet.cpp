class Solution {
public:
    // Intuition: for a car (A), to form a car fleet with the car (B) in front of it, it needs to
    // catch up B before B arrives at the target. That is, if A can pass B, then A takes less time
    // then B to arrive at the target. Therefore, we can firstly assume that each car can pass the
    // cars ahead, and compute the time they'll take. If a car A start from a larger position then
    // B, but B takes less time then A, then A and B will form a car fleet.
    
    // Approach: compute the time a car will arrive at the target assuming that each car can pass
    // all the others, storing in the time array "time". Then sort "time" in reverse order of the
    // position. We loop through time from 0 to n - 1, grouping the non-increasing groups. Each group
    // is the car fleet. For example, [3,2,1] have one non-increasing group.

    // Time: O(n*log(n))
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

        int n_car_fleets = 1;
        double max_val = sorted_time[0];
        for (int i = 1; i < n; i++) {
            if (sorted_time[i] > max_val) {
                max_val = sorted_time[i];
                n_car_fleets++;
            }
        }
        
        return n_car_fleets;
    }
};