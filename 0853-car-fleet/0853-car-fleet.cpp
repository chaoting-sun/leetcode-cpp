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

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, double>> positionTime(n);
        for (int i = 0; i < n; i++) {
            positionTime[i] = { position[i], (target - position[i]) * 1.0 / speed[i] };
        }
        sort(positionTime.begin(), positionTime.end(), [](pair<int,double> &a, pair<int,double> &b) {
            return a.first > b.first;
        });

        stack<double> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || stk.top() < positionTime[i].second) {
                stk.push(positionTime[i].second);
            }
        }
        return stk.size();
    }
};