// ## Understand
// 1. What is the size range of arr? Can the arr be empty?
//  - 1 <= arr.length <= 5 * 10^4


// ## Match & Plan
// The problem asks us to return the minimum number of steps from
// index 0 to index the last one. Therefore, the most intuitive
// method is to use BFS. I start from index 0, every time, I try
// the three options to the next unvisited index. The problem is
// that while the first two options take O(1), the third option
// takes O(n), which cause the time complexity to O(n^2) at most.
// I can optimize the time complexity of the third option. I can
// precompute the indexes of a value in hashmap, then I can directly
// jump to the other index with the same value by this map.
// Building the hashmap takes O(n), and all the state transition
// takes O(1), with n elements in the array. So it takes O(n) in total.


// ## Implement

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        // precompute the indexes of value for fast lookup
        unordered_map<int, vector<int>> value_indexes;
        for (int i = 0; i < n; i++) {
            value_indexes[arr[i]].push_back(i);
        }

        // BFS
        queue<int> positions;
        vector<bool> visited(n, false);

        positions.push(0);
        visited[0] = true;
        int steps = 0;

        while (!positions.empty()) {
            int size = positions.size();
            while (size--) {
                int current_position = positions.front();
                positions.pop();
                if (current_position == n - 1) return steps;

                // first option
                if (current_position < n - 1 && !visited[current_position + 1]) {
                    positions.push(current_position + 1);
                    visited[current_position + 1] = true;
                }
                // second option
                if (current_position > 0 && !visited[current_position - 1]) {
                    positions.push(current_position - 1);
                    visited[current_position - 1] = true;
                }
                // third option
                if (value_indexes.count(arr[current_position])) {
                    for (int next_position: value_indexes[arr[current_position]]) {
                        if (visited[next_position]) continue;
                        positions.push(next_position);
                        visited[next_position] = true;
                    }
                    value_indexes.erase(arr[current_position]);
                }
            }

            steps++;
        }

        return steps;
    }
};

// ## Review

// - Edge case: arr = [1]
// value_indexes = { 0: [0] }
// visited = [f]
// positions = [0]
// visited = [t]
// steps = 0
// BFS
// size = 1
// return steps (0)

// - When we should jump to be fast: arr = [1, 3, 4, 1, 5]
// value_indexes: { 1: [0, 3], 3: [1], 4: [2], 5: [4] }
// visited = [f,f,f,f,f]
// positions = [0]
// visited = [t,f,f,f,f]
// steps = 0

// BFS

// - size = 1, steps = 0
//  - current_position = 0
//  - positions = []
//  - first:
//   - positions = [1]
//   - visited = [t,t,f,f,f]
//  - second:
//   - x
//  - third:
//   - positions = [1, 3]
//   - value_indexes: { 3: [1], 4: [2], 5: [4] }

// - size = 2, steps = 1
//  - current_position = 1
//  - positions = [3]
//  - first:
//   - positions = [3, 2]
//   - visited = [t,t,t,f,f]
//  - second:
//   - x
//  - third:
//   - x
//   - value_indexes: { 4: [2], 5: [4] }
//  - current_position = 3
//  - positions = []
//  - first:
//   - positions: [3, 2, 4]
//  ...

// - step = 2
// pop 4 == n - 1 -> return step (2)


// ## Evaluate


// Submit Error
// 1. Spell Wrong
// position.pop();
// to
// positions.pop();

// 2. Spell Wrong
// for (int next_position: value_indexes[curent_position]) {
// to
// for (int next_position: value_indexes[current_position]) {

// 3. Wrong Answer
// for (int next_position: value_indexes[current_position])
// to
// for (int next_position: value_indexes[arr[current_position]])