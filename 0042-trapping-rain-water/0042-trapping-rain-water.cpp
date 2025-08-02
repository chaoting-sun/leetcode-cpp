class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        
        int h_max = 0;
        for (int i = 0 ; i < n; i++) {
            h_max = max(h_max, height[i]);
            left_max[i] = h_max;
        }

        h_max = 0;
        for (int i = n - 1; i >= 0; i--) {
            h_max = max(h_max, height[i]);
            right_max[i] = h_max;
        }

        int amount = 0;
        for (int i = 0; i < n; i++) {
            int h_left_and_right = min(left_max[i], right_max[i]);
            amount += h_left_and_right - height[i];
        }

        return amount;
    }
};