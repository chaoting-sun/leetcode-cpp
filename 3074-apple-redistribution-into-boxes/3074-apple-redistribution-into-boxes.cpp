class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size();

        int totalApples = 0;
        for (int i = 0; i < n; i++) totalApples += apple[i];
        
        sort(capacity.begin(), capacity.end(), [](int c1, int c2) {
            return c1 > c2;
        });
        int totalCapacity = 0;
        for (int i = 0; i < m; i++) {
            totalCapacity += capacity[i];
            if (totalCapacity >= totalApples) {
                return i + 1;
            }
        }
        return -1;
    }
};