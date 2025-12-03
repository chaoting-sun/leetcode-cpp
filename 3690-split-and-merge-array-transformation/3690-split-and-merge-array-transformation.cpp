class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        // change to 0~size-1
        int n = nums1.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) mp[nums1[i]] = i;
        for (int i = 0; i < n; i++) {
            nums1[i] = mp[nums1[i]];
            nums2[i] = mp[nums2[i]];
        }

        // initialize
        unordered_set<string> visited;
        visited.reserve(720);
        string s = "";
        for (int d: nums1) s += d + '0';
        visited.insert(s);

        queue<vector<int>> q;
        q.push(nums1);
        int steps = 0;

        // bfs
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto curr = q.front(); // [3,1,2]
                q.pop();
                if (curr == nums2) return steps;

                for (int i = 0; i < n; i++) {
                    for (int j = i; j < n; j++) {
                        vector<int> removed(j - i + 1);
                        vector<int> left;
                        for (int k = i; k <= j; k++) removed[k - i] = curr[k];
                        for (int k = 0; k < i; k++) left.push_back(curr[k]);
                        for (int k = j + 1; k < n; k++) left.push_back(curr[k]);

                        for (int k = 0; k <= left.size(); k++) {
                            vector<int> next = left;
                            next.insert(next.begin() + k, removed.begin(), removed.end());
                            string s = "";
                            for (int d: next) s += d + '0';
                            if (visited.count(s)) continue;
                            visited.insert(s);
                            q.push(next);
                        }
                    }
                }
            }

            steps++;
        }
        
        return -1;
    }
};