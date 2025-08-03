class Solution {
public:
    // Intuition: For each element, we need to find the index difference from it and the latter element.
    // One way is to traverse the array, and look for the larger element that is larger than the current
    // element, which will take O(n^2) time. When we think deeply, we have to see the latter element then
    // we can know the previous element. Stack is the data structure that we can put elements into for later
    // use. Also, this question want us to compare the previous and latter elements, so it may be related
    // to use a monotonic stack to implement.
    // Approach: Monotonic Stack.
    // Maintain a monotonic stack (large -> small) in which each element is a pair { value, index }.
    // We traverse the array, and push the element into the stack. When there is an element that has value
    // smaller than the current one, then pop it and store the index difference.
    // When we finish traversing, the elements that are inside the stack are those have no latter element larger then them.

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st; // value, index
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                int index = st.top().second;
                ans[index] = i - index;
                st.pop();
            }
            st.push({ temperatures[i], i });
        }
        return ans;
    }
};