class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (auto& booking: bookings) {
            int first = booking[0], last = booking[1], seats = booking[2];
            for (int i = first; i <= last; i++) {
                ans[i - 1] += seats;
            }
        }
        return ans;   
    }
};