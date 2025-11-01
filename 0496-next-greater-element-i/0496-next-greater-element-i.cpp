class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk; // decreasing stack
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int,int> nextGreater(n2);
        
        for (int i = n2 - 1; i >= 0; i--) {
            while (!stk.empty() && nums2[i] >= nums2[stk.top()]) {
                stk.pop();
            }
            nextGreater[nums2[i]] = stk.empty() ? -1 : nums2[stk.top()];
            stk.push(i);
        }

        vector<int> ans(n1);
        for (int i = 0; i < n1; i++) ans[i] = nextGreater[nums1[i]];
        return ans;
    }
};


// class Solution {
// public:
//     // Approach: Monotonic Stack
//     // Time: O(n1 + n2)
//     // Space: O(n2)

//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size(), n2 = nums2.size();

//         stack<int> value_stack;
//         vector<int> nge(n1, -1);
//         unordered_map<int,int> nge_map;

//         for (int i = 0; i < n2; i++) {
//             while (!value_stack.empty() && value_stack.top() < nums2[i]) {
//                 nge_map[value_stack.top()] = nums2[i];
//                 value_stack.pop();
//             }
//             value_stack.push(nums2[i]);
//         }

//         for (int i = 0; i < n1; i++) {
//             if (nge_map.count(nums1[i])) {
//                 nge[i] = nge_map[nums1[i]];
//             }
//         }

//         return nge;
//     }
// };