class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq; // max heap // (fuel)
        
        int maxReach = startFuel;
        int stationIdx = 0;
        int stops = 0;

        sort(stations.begin(), stations.end());
        while (maxReach < target) {
            while (stationIdx < n && maxReach >= stations[stationIdx][0]) {
                pq.push(stations[stationIdx][1]);
                stationIdx++;
            }
            if (pq.empty()) break;
            maxReach += pq.top();
            pq.pop();
            stops++;
        }

        return maxReach < target ? -1 : stops;
    }
};

// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         int n = stations.size();
//         priority_queue<pair<int,int>> pq; // max heap // (position + fuel, index)
        
//         int currentPosition = 0;
//         int currentFuel = startFuel;
//         int stationIdx = 0;
//         int stops = 0;

//         sort(stations.begin(), stations.end());

//         while (currentPosition + currentFuel < target) {
//             while (stationIdx < n && currentPosition + currentFuel >= stations[stationIdx][0]) {
//                 pq.push({ stations[stationIdx][1], stationIdx });
//                 stationIdx++;
//             }

//             if (pq.empty()) break;

//             auto [fuelToAdd, idx] = pq.top();
//             pq.pop();
//             currentFuel = currentFuel - (stations[idx][0] - currentPosition) + fuelToAdd;
//             currentPosition = stations[idx][0];
//             stops++;
//         }

//         return currentPosition + currentFuel < target ? -1 : stops;
//     }
// };