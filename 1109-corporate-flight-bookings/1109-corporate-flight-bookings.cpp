class Solution {
public:
    // Approach: Brute-force
    // Time: O(n^2)
    // Space: O(1)

    // vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    //     vector<int> ans(n);
    //     for (auto& booking: bookings) {
    //         int first = booking[0], last = booking[1], seats = booking[2];
    //         for (int i = first; i <= last; i++) {
    //             ans[i - 1] += seats;
    //         }
    //     }
    //     return ans;
    // }

    // Approach: Line Sweep
    // Time: O(n)
    // Space: O(1)

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (auto& booking: bookings) {
            int first = booking[0], last = booking[1], seats = booking[2];
            ans[first - 1] += seats;
            if (last < n) ans[last] -= seats;
        }
        for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
        return ans;
    }  
};