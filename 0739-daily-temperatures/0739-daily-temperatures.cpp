class Solution {
public:
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

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int index = st.top();
                ans[index] = i - index;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};