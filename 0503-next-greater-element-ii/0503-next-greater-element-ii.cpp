class Solution {
public:
    // Approach: Monotonic Stack with doubled array

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> index_stack;
        vector<int> ans(n, -1);
        
        for (int i = 0; i < 2 * n; i++) {
            while (!index_stack.empty() && nums[index_stack.top() % n] < nums[i % n]) {
                if (index_stack.top() < n) ans[index_stack.top()] = nums[i % n];
                index_stack.pop();
            }
            index_stack.push(i);
        }
        return ans;
    }
};