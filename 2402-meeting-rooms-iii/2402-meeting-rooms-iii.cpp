using ll = long long;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        set<int> availableRooms;
        for (int i = 0; i < n; i++) availableRooms.insert(i);
        sort(meetings.begin(), meetings.end());
        vector<int> useCount(n);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> minHeap; // end time, used room
        ll time = 0;
        int meetingIdx = 0;
        while (meetingIdx < meetings.size()) {
            auto& meeting = meetings[meetingIdx];
            while (!minHeap.empty() && minHeap.top().first <= time) {
                availableRooms.insert(minHeap.top().second); // release room
                minHeap.pop();
            }
            if (availableRooms.empty()) {
                time = minHeap.top().first;
                continue;
            }
            if (time < (ll)meeting[0]) {
                time = meeting[0];
                continue;
            }
            int room = *availableRooms.begin();
            availableRooms.erase(room);
            minHeap.push({ time + (meeting[1] - meeting[0]), room });
            meetingIdx++;
            useCount[room]++;
        }

        int maxUsedCount = -1, maxUsedRoom = -1;
        for (int i = 0; i < n; i++) {
            if (useCount[i] > maxUsedCount) {
                maxUsedRoom = i;
                maxUsedCount = useCount[i];
            }
        }

        return maxUsedRoom;
    }
};

// n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]

// availableRooms = { 0, 1 }
// useCount = [0, 0]
// time = 0

// meetingIdx = 0
// availableRooms = {1}
// minHeap = {{ 10, 0 }}
// useCount = [1, 0]

// time = 1


// n
// meetings = [start, end]
// start

// availableRooms = set { 0, 1, ..., n - 1 }
// useCount = [ ] 0 +1+1

// min heap key = meeting end
// time = 0

// loop meetings
//     while there are ended meetings given time
//         pop from min heap
//         insert availableRooms

//     if availableRooms is empty
//         time = end time of the top in min heap
//         continue
    
//     if time < start of meeting:
//         time = start of meeting
//         continue

//     use the first room
//     set useCount

// find the lowest room with the most used count