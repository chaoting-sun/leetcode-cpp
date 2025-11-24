class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxLength = 0;
        vector<int> prefix(n);
        unordered_map<int, int> visited;

        visited.insert({ 0, -1 }); // visited = { 0: -1 }
        prefix[0] = nums[0] == 1 ? 1 : -1; // prefix[0] = -1
        visited.insert({ prefix[0], 0 }); // visited = { 0: -1, -1: 0 }
        
        for (int i = 1; i < n; i++) { // i == 1
            prefix[i] = prefix[i - 1] + (nums[i] == 1 ? 1 : -1); // prefix[1] = -1 + 1 = 0
            if (visited.count(prefix[i])) {
                maxLength = max(maxLength, i - visited[prefix[i]]); // minLength = 1 - (-1) = 2
            } else {
                visited.insert({ prefix[i], i });
            }
        }

        return maxLength == INT_MAX ? 0 : maxLength;
    }
};

// [0, 1]

// visited = { 0: -1, -1: 0 }
// prefix = [-1, 0]