class Solution {
public:
    // Approach1: Brute-force. Loop the height array, and find the maximum height
    // from left side and right side to caculate the amount of water.
    // Time: O(n^2)
    // Space: O(1)
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     int amount = 0;

    //     for (int i = 0; i < n; i++) {
    //         int left_max = 0, right_max = 0;

    //         for (int j = 0; j < i; j++) left_max = max(left_max, height[j]);
    //         for (int j = i + 1; j < n; j++) right_max = max(right_max, height[j]);
    //         int h_left_and_right = min(left_max, right_max);
    //         if (h_left_and_right > height[i]) amount += h_left_and_right - height[i];
    //     }

    //     return amount;
    // }

    // Approach2: Maintain right max and left max values for each element
    // Intuition: For each element, the amount of water it has is determined
    // by the maximum height from both the left and right side. If it is shorter
    // then then both, then it will have water with amount:
    // min(max. left height, max. right height) - height[i]
    // Time: O(n), where n is the length of height
    // Space: O(n), including left_max, right_max.

    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<int> left_max(n), right_max(n);
        
    //     int h_max = 0;
    //     for (int i = 0 ; i < n; i++) {
    //         h_max = max(h_max, height[i]);
    //         left_max[i] = h_max;
    //     }

    //     h_max = 0;
    //     for (int i = n - 1; i >= 0; i--) {
    //         h_max = max(h_max, height[i]);
    //         right_max[i] = h_max;
    //     }

    //     int amount = 0;
    //     for (int i = 0; i < n; i++) {
    //         int h_left_and_right = min(left_max[i], right_max[i]);
    //         amount += h_left_and_right - height[i];
    //     }

    //     return amount;
    // }

    // Approach3: Monotonic Stack

    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int amount = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int h_bounded = min(height[st.top()], height[i]) - height[top];
                int w_bounded = i - st.top() - 1;
                amount += h_bounded * w_bounded;
            }
            st.push(i);
        }

        return amount;
    }

};