class Solution {
public:
    // Find nearest greater to the right -> monotonic stack -> decreasing
    // current temperatures[i] > temperatures[stack.top()];
    // ans[stack.top()] = i - stack.top();
    // current temperatures[i] <= temperatures[stack.top()];
    // push to stack

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> days(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                days[stk.top()] = i - stk.top();
                stk.pop();   
            }
            stk.push(i);
        }
        return days;
    }
};

// class Solution {
// public:
    // Intuition: For each element, we need to find the difference in indices between it and the next element that is greater.
    // A straightforward way is to traverse the array and look for the next warmer day for each element, which takes O(n^2) time.
    // However, if we look deeper, we realize we need information about future elements to resolve the answer for earlier ones. 
    // A stack is well-suited for this purpose, as it allows us to keep track of unresolved elements while traversing the array.
    // Since we want to compare previous and upcoming elements, a monotonic stack can help us efficiently find the next greater element.

    // Approach: Monotonic Stack
    // We maintain a decreasing stack (each element is a pair: { value, index }).
    // As we traverse the array, we push the current element onto the stack.
    // Whenever the current value is greater than the value at the top of the stack, we pop from the stack and store the index difference in the result.
    // At the end of the traversal, any indices left in the stack do not have a future warmer day.

    // Time Complexity: O(n) – each element is pushed and popped at most once.
    // Space Complexity: O(n)

    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     int n = temperatures.size();
    //     stack<pair<int, int>> st; // value, index
    //     vector<int> ans(n);

    //     for (int i = 0; i < n; i++) {
    //         while (!st.empty() && st.top().first < temperatures[i]) {
    //             int index = st.top().second;
    //             ans[index] = i - index;
    //             st.pop();
    //         }
    //         st.push({ temperatures[i], i });
    //     }
    //     return ans;
    // }

    // To optimize: We don't have to store the value into the stack

    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     int n = temperatures.size();
    //     stack<int> st;
    //     vector<int> ans(n);

    //     for (int i = 0; i < n; i++) {
    //         while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
    //             int index = st.top();
    //             ans[index] = i - index;
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    //     return ans;
    // }

    // Intuition: Previously, we used a stack because we needed information about future elements to answer earlier elements.
    // However, if we traverse the array backward, for each element, we already have the necessary information to determine its answer.
    // As we process each day from the end toward the start, we can use the results we've already computed to efficiently find the next warmer day.

    // Approach: Backward Traversal with Optimized Space.
    // - Start from the second-to-last element and traverse backward.
    // - For each element at index i, compare it to the next day (i+1):
    //   - If temperatures[i] < temperatures[i+1], then ans[i] = 1.
    //   - If temperatures[i] >= temperatures[i+1], initialize a variable `days = 1` and set `current_day = i + 1`.
    //     - Use previously computed answers to jump forward: while temperatures[i] >= temperatures[current_day] and ans[current_day] != 0,
    //       increment `days` by ans[current_day] and move `current_day` forward by ans[current_day].
    //   - If there is no warmer day ahead, ans[i] remains 0.
    // - Maintain a variable `hottest` to track the maximum temperature seen so far while traversing. If temperatures[i] > hottest, update hottest and leave ans[i] = 0.

    // Time Complexity: O(n), since each index is visited at most once via jumps.
    // Space Complexity: O(1) (excluding the output array).

//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> ans(n);
//         int hottest = temperatures[n - 1];

//         for (int i = n - 2; i >= 0; i--) {
//             if (temperatures[i] >= hottest) {
//                 hottest = temperatures[i];
//                 continue;
//             }

//             if (temperatures[i] < temperatures[i + 1]) {
//                 ans[i] = 1;
//             } else {
//                 int days = 1;
//                 int current_day = i + 1;
//                 while (temperatures[i] >= temperatures[current_day] && ans[current_day] != 0) {
//                     days += ans[current_day];
//                     current_day += ans[current_day];
//                 }
//                 ans[i] = days;
//             }

//             hottest = max(hottest, temperatures[i]);
//         }

//         return ans;
//     }
// };
