using ll = long long;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        set<int> availableRooms;
        for (int i = 0; i < n; i++) availableRooms.insert(i);
        sort(meetings.begin(), meetings.end());
        vector<int> useCount(n);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> busy; // end time, used room

        for (auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            int duration = end - start;
            
            while (!busy.empty() && busy.top().first <= start) {
                availableRooms.insert(busy.top().second); // release room
                busy.pop();
            }
            
            if (!availableRooms.empty()) {
                // has available room -> assign the meeting to the room
                int room = *availableRooms.begin();
                availableRooms.erase(room);
                busy.push({ end, room });
                useCount[room]++;
            } else {
                // no available room -> assume that the earliest end time of a meeting has been arrived, and then remove it
                auto [earliestEndTime, room] = busy.top();
                busy.pop();
                busy.push({ earliestEndTime + duration, room });
                useCount[room]++;
            }
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