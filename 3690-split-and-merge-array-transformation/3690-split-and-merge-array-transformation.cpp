class Solution {
public:
    string getKey(vector<int>& nums) {
        string key = "";
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > 0) key += ",";
            key += to_string(nums[i]);
        }
        return key;
    }

    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if (n == 0 || nums1 == nums2) return 0;
        
        queue<pair<vector<int>,int>> q;
        unordered_set<string> visited;

        q.push({ nums1, 0 });
        visited.insert(getKey(nums1));

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            for (int left = 0; left < n; left++) {
                for (int right = left; right < n; right++) {
                    vector<int> block(curr.begin() + left, curr.begin() + right + 1);
                    vector<int> rest;
                    rest.insert(rest.end(), curr.begin(), curr.begin() + left);
                    rest.insert(rest.end(), curr.begin() + right + 1, curr.end());

                    int m = rest.size();
                    for (int gap = 0; gap <= m; gap++) {
                        vector<int> nxt;
                        nxt.insert(nxt.end(), rest.begin(), rest.end());
                        nxt.insert(nxt.begin() + gap, block.begin(), block.end());

                        if (nxt == nums2) return dist + 1;
                        
                        string key = getKey(nxt);
                        if (visited.count(key)) continue;
                        visited.insert(key);

                        q.push({ nxt, dist + 1 });
                    }
                }
            }
        }

        return 0;
    }
};

