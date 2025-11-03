class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk; // monotonic increasing stack
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return ans;
    }
};

// class Solution {
// public:
//     // Intuition: For each element, we need to find the difference in indices between it and the next element that is greater.
//     // A straightforward way is to traverse the array and look for the next warmer day for each element, which takes O(n^2) time.
//     // However, if we look deeper, we realize we need information about future elements to resolve the answer for earlier ones. 
//     // A stack is well-suited for this purpose, as it allows us to keep track of unresolved elements while traversing the array.
//     // Since we want to compare previous and upcoming elements, a monotonic stack can help us efficiently find the next greater element.

//     // Approach: Monotonic Stack
//     // We maintain a decreasing stack (each element is a pair: { value, index }).
//     // As we traverse the array, we push the current element onto the stack.
//     // Whenever the current value is greater than the value at the top of the stack, we pop from the stack and store the index difference in the result.
//     // At the end of the traversal, any indices left in the stack do not have a future warmer day.

//     // Time Complexity: O(n) – each element is pushed and popped at most once.
//     // Space Complexity: O(n)

//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int numDays = temperatures.size();
//         stack<int> indexStack;
//         vector<int> waitDays(numDays);
//         for (int day = 0; day < numDays; day++) {
//             while (!indexStack.empty() && temperatures[indexStack.top()] < temperatures[day]) {
//                 waitDays[indexStack.top()] = day - indexStack.top();
//                 indexStack.pop();   
//             }
//             indexStack.push(day);
//         }
//         return waitDays;
//     }

//     // Intuition: Previously, we used a stack because we needed information about future elements to answer earlier elements.
//     // However, if we traverse the array backward, for each element, we already have the necessary information to determine its answer.
//     // As we process each day from the end toward the start, we can use the results we've already computed to efficiently find the next warmer day.

//     // Approach: Backward Traversal with Optimized Space.
//     // - Start from the second-to-last element and traverse backward.
//     // - For each element at index i, compare it to the next day (i+1):
//     //   - If temperatures[i] < temperatures[i+1], then ans[i] = 1.
//     //   - If temperatures[i] >= temperatures[i+1], initialize a variable `days = 1` and set `current_day = i + 1`.
//     //     - Use previously computed answers to jump forward: while temperatures[i] >= temperatures[current_day] and ans[current_day] != 0,
//     //       increment `days` by ans[current_day] and move `current_day` forward by ans[current_day].
//     //   - If there is no warmer day ahead, ans[i] remains 0.
//     // - Maintain a variable `hottest` to track the maximum temperature seen so far while traversing. If temperatures[i] > hottest, update hottest and leave ans[i] = 0.

//     // Time Complexity: O(n), since each index is visited at most once via jumps.
//     // Space Complexity: O(1) (excluding the output array).

//     // vector<int> dailyTemperatures(vector<int>& temperatures) {
//     //     int numDays = temperatures.size();
//     //     vector<int> waitDays(numDays);
//     //     int hottestTemp = temperatures[numDays - 1];
//     //     for (int day = numDays - 2; day >= 0; day--) {
//     //         if (temperatures[day] >= hottestTemp) {
//     //             hottestTemp = temperatures[day];
//     //             continue;
//     //         }
//     //         if (temperatures[day] < temperatures[day + 1]) {
//     //             waitDays[day] = 1;
//     //         } else {
//     //             int nextDay = day + 1;
//     //             while (temperatures[day] >= temperatures[nextDay] && temperatures[nextDay] != 0) {
//     //                 nextDay += waitDays[nextDay];
//     //             }
//     //             waitDays[day] = nextDay - day;
//     //         }
//     //     }
//     //     return waitDays;
//     // }
// };
