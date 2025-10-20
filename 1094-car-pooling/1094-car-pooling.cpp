class Solution {
public:
    // Approach: Line Sweep
    // Time: O(nlogn)
    // Space: O(n)

    // bool carPooling(vector<vector<int>>& trips, int capacity) {
    //     map<int,int> passengerChanges;
    //     for (auto& trip: trips) {
    //         int numPassengers = trip[0], from = trip[1], to = trip[2];
    //         passengerChanges[from] += numPassengers;
    //         passengerChanges[to] -= numPassengers;
    //     }
    //     int currentPassengers = 0;
    //     for (auto& [_, delta]: passengerChanges) {
    //         currentPassengers += delta;
    //         if (currentPassengers > capacity) return false;
    //     }
    //     return true;
    // }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int>& t1, vector<int>& t2) {
            return t1[1] < t2[1];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        int currentPassengers = 0;
        for (auto& trip: trips) {
            int numPassengers = trip[0], from = trip[1], to = trip[2];
            while (!minHeap.empty() && minHeap.top().first <= from) {
                currentPassengers -= minHeap.top().second;
                minHeap.pop();
            }
            minHeap.push({ to, numPassengers });
            currentPassengers += numPassengers;
            if (currentPassengers > capacity) {
                return false;
            }
        }
        return true;
    }
};