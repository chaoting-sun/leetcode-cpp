// class Solution {
// public:
//     bool canReach(vector<int>& arr, int start) {
//         int n = arr.size();
//         if (n == 0) return false;

//         vector<bool> jumped(n, false);
        
//         queue<int> q;
//         q.push(start);
//         jumped[start] = true;
        
//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
//             if (arr[curr] == 0) return true;
            
//             int prev = curr - arr[curr];
//             int next = curr + arr[curr];
//             if (prev >= 0 && !jumped[prev]) {
//                 q.push(prev);
//                 jumped[prev] = true;
//             }
//             if (next < n && !jumped[next]) {
//                 q.push(next);
//                 jumped[next] = true;
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if (n == 0) return false;
        
        queue<int> q;
        q.push(start);
        arr[start] = -arr[start];
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (arr[curr] == 0) return true;
            
            int prev = curr - arr[curr];
            if (prev < n && prev >= 0 && arr[prev] >= 0) {
                q.push(prev);
                arr[prev] = -arr[prev];
            }

            int next = curr + arr[curr];
            if (next < n && next >= 0 && arr[next] >= 0) {
                q.push(next);
                arr[next] = -arr[next];
            }
        }

        return false;
    }
};