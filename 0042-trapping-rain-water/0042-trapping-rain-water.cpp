class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        
        int max_value = 0;
        for (int i = 0; i < n; i++) {
            left_max[i] = max_value;
            max_value = max(max_value, height[i]);
        }
        max_value = 0;
        for (int i = n - 1; i >= 0; i--) {
            right_max[i] = max_value;
            max_value = max(max_value, height[i]);
        }
        int amount = 0;
        for (int i = 0; i < n; i++) {
            int min_height = min(left_max[i], right_max[i]);
            if (min_height > height[i]) amount += min_height - height[i];
        }
        return amount;
    }
};

// class Solution {
// public:
//     // Approach1: Brute-force. Loop the height array, and find the maximum height
//     // from left side and right side to calculate the amount of water.
//     // Time: O(n^2)
//     // Space: O(1)
//     // int trap(vector<int>& height) {
//     //     int n = height.size();
//     //     int amount = 0;

//     //     for (int i = 0; i < n; i++) {
//     //         int left_max = 0, right_max = 0;

//     //         for (int j = 0; j < i; j++) left_max = max(left_max, height[j]);
//     //         for (int j = i + 1; j < n; j++) right_max = max(right_max, height[j]);
//     //         int h_left_and_right = min(left_max, right_max);
//     //         if (h_left_and_right > height[i]) amount += h_left_and_right - height[i];
//     //     }

//     //     return amount;
//     // }

//     // Approach2: Maintain right max and left max values for each element
//     // Intuition: For each element, the amount of water it has is determined
//     // by the maximum height from both the left and right side. If it is shorter
//     // then then both, then it will have water with amount:
//     // min(max. left height, max. right height) - height[i]
//     // Time: O(n), where n is the length of height
//     // Space: O(n), including left_max, right_max.

//     // int trap(vector<int>& height) {
//     //     int n = height.size();
//     //     vector<int> left_max(n), right_max(n);
        
//     //     int h_max = 0;
//     //     for (int i = 0 ; i < n; i++) {
//     //         h_max = max(h_max, height[i]);
//     //         left_max[i] = h_max;
//     //     }

//     //     h_max = 0;
//     //     for (int i = n - 1; i >= 0; i--) {
//     //         h_max = max(h_max, height[i]);
//     //         right_max[i] = h_max;
//     //     }

//     //     int amount = 0;
//     //     for (int i = 0; i < n; i++) {
//     //         int h_left_and_right = min(left_max[i], right_max[i]);
//     //         amount += h_left_and_right - height[i];
//     //     }

//     //     return amount;
//     // }

//     // Approach3: Monotonic Stack
//     // Intuition:
//     // We use a decreasing stack to identify "valleys" where water can be trapped.
//     // Each time we find a bar taller than the top of the stack, it means we've
//     // discovered a right boundary for one or more valleys.
//     //
//     // When a bar is popped as `top`, we compute the water directly above it. The
//     // left boundary is now `st.top()` (after popping), and the right boundary is
//     // the current bar. The same physical bar can later serve as a left boundary
//     // or even become a bottom of a larger valley if an even taller right boundary
//     // appears. This is why the algorithm sometimes computes water involving the
//     // same bar at different times.
//     //
//     // This step-by-step, "inside-out" processing ensures that each bounded
//     // region is computed exactly once without overcounting.

//     // Time: O(n). For every element, they can at most got pushed and popped one time.
//     // Space: O(n)

//     // int trap(vector<int>& height) {
//     //     int n = height.size();
//     //     stack<int> st;
//     //     int amount = 0;

//     //     for (int i = 0; i < n; i++) {
//     //         while (!st.empty() && height[st.top()] < height[i]) {
//     //             int top = st.top();
//     //             st.pop();
//     //             if (st.empty()) break;
//     //             int h_bounded = min(height[st.top()], height[i]) - height[top];
//     //             int w_bounded = i - st.top() - 1;
//     //             amount += h_bounded * w_bounded;
//     //         }
//     //         st.push(i);
//     //     }

//     //     return amount;
//     // }

//     // Approach 4: Two Pointers
//     // Intuition:
//     // For each bar, the amount of water it can trap is determined by the minimum of the highest bar on its left
//     // and the highest bar on its right. In other words, water at each position = min(max_left, max_right) - height[i].
//     //
//     // To implement this efficiently, we can use two pointers: one starting from the left, and one from the right.
//     // We also maintain the maximum heights we've seen so far from the left (l_max) and right (r_max).
//     //
//     // The key insight is: At any step, whichever side has the smaller current max (l_max or r_max) is the limiting factor 
//     // for water on that side. If l_max < r_max, we know that the water trapped at the left pointer depends only on l_max,
//     // because no matter how tall the bar is to the right, l_max is the bottleneck for the current position.
//     //
//     // So:
//     // - When l_max < r_max: we process the left pointer. The water trapped at this bar is l_max - height[left].
//     //   We then update l_max if needed and move the left pointer inward.
//     // - When r_max <= l_max: we process the right pointer, since r_max is the bottleneck.
//     //   The water trapped at this bar is r_max - height[right]. We update r_max if needed and move the right pointer inward.
//     //
//     // We continue until the pointers meet. This way, we only need a single pass through the array, and no extra space.
//     //
//     // Time Complexity: O(n) -- each bar is visited at most once.
//     // Space Complexity: O(1) -- only a few variables are used for tracking state.

//     int trap(vector<int>& height) {
//         int n = height.size();
//         int amount = 0;
//         int left = 0, right = n - 1;
//         int l_max = height[left], r_max = height[right];

//         while (left <= right) {
//             if (l_max < r_max) {
//                 l_max = max(l_max, height[left]);
//                 amount += l_max - height[left];
//                 left++;
//             } else {
//                 r_max = max(r_max, height[right]);
//                 amount += r_max - height[right];
//                 right--;
//             }
//         }

//         return amount;
//     }
// };