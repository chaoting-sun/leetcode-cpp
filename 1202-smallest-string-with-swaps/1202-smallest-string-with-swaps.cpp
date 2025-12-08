// Understand:

// Can s be empty? -> length of s >= 1
// What is the range of length of s => 1 <= length of s <= 10^5
// Can pairs be empty? -> yes
// What is the range of length of pairs -> 0 <= length of pairs <= 10^5

// Match & Plan:

// We can think of the pairs as the edges on multiple connected graphs,
// in which the characters are the nodes. In each connected graphs, we
// can swap the nodes until they are lexicographically sammlest.

// The method I will use, will be
// 1. find all distinct connected graphs
// 2. in each graphs, we sort the characters
// 3. return the sorted result of s

// Implementation

class Solution {
private:
    void dfs(string& s, vector<vector<int>>& adjacency_list, vector<int>& visited, vector<int>& char_list, vector<int>& index_list, int current_node_index) {
        // mark as visited
        visited[current_node_index] = true;
        char_list.push_back(s[current_node_index]);
        index_list.push_back(current_node_index);

        for (int node_index: adjacency_list[current_node_index]) {
            if (!visited[node_index]) {
                dfs(s, adjacency_list, visited, char_list, index_list, node_index);
            }
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int s_length = s.size();// 4
        int pairs_length = pairs.size(); // 3

        // base case: no pairs to swap
        if (pairs_length == 0) return s;

        // building an adjacency list
        vector<vector<int>> adjacency_list(s_length);
        for (int i = 0; i < pairs_length; i++) {
            int node_a = pairs[i][0];
            int node_b = pairs[i][1];
            adjacency_list[node_a].push_back(node_b);
            adjacency_list[node_b].push_back(node_a);
        }

        string final_s = s;

        // dfs on all nodes
        vector<int> visited(s_length, false);

        for (int i = 0; i < s_length; i++) {
            if (!visited[i]) {
                vector<int> char_list, index_list;
                dfs(s, adjacency_list, visited, char_list, index_list, i);
                sort(char_list.begin(), char_list.end());
                sort(index_list.begin(), index_list.end());
                for (int j = 0; j < char_list.size(); j++) {
                    final_s[index_list[j]] = char_list[j];
                }
            }        
        }

        return final_s;
    }
};

// Review

// s = 'a'

// s = "dcab", pairs = [[0,3],[1,2],[0,2]]

// adj. list
// 0 -> 3, 2
// 1 -> 2
// 2 -> 1, 0
// 3 -> 0

// visited = [F, F, F, F]
// i = 0 -> !visited[0] = T
// char_list = []
// index_list = []

// current_node_index == 0
// visited = [T, F, F, F]
// char_list = [d]
// index_list = [0]

// current_node_index == 3
// visited = [T, F, F, T]
// char_list = [d,b]
// index_list = [0,3]

// current_node_index == 2
// visited = [T, F, T, T]
// char_list = [d,b,a]
// index_list = [0,3,2]

// current_node_index == 1
// visited = [T, T, T, T]
// char_list = [d,b,a,c]
// index_list = [0,3,2,1]

// sort
// char_list = [a,b,c,d]
// index_list = [0,1,2,3]

// refill
// final_s = 'abcd'


// Submit Errors (error -> updated)

// for (int node_index: adjacency_list)
// for (int node_index: adjacency_list[current_node_index])

// PairsDfs(s, adjacency_list, visited, char_list, index_list, i);
// dfs(s, adjacency_list, visited, char_list, index_list, i);