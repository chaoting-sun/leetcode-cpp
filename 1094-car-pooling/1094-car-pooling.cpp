class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> passengerChanges;
        for (auto& trip: trips) {
            int numPassengers = trip[0], from = trip[1], to = trip[2];
            passengerChanges[from] += numPassengers;
            passengerChanges[to] -= numPassengers;
        }
        int currentPassengers = 0;
        for (auto& [_, delta]: passengerChanges) {
            currentPassengers += delta;
            if (currentPassengers > capacity) return false;
        }
        return true;
    }
};