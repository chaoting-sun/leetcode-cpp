class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strs_sorted = strs;
        for (auto& each: strs_sorted) {
            sort(each.begin(), each.end());
        }

        int n = strs.size();
        vector<int> ids(n);
        for (int i = 0; i < n; i++) {
            ids[i] = i;
        }
        
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return strs_sorted[i] < strs_sorted[j];
        });
        sort(strs_sorted.begin(), strs_sorted.end());

        for (int i = 0; i < n; i++) {
            cout << strs_sorted[i] << " ";
        }

        vector<vector<string>> ans(0);
        vector<string> backet(0);
        string current = "";

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                backet.push_back(strs[ids[i]]);
                current = strs_sorted[i];
            } else {
                if (strs_sorted[i] != current) {
                    ans.push_back(backet);
                    backet.clear();
                    current = strs_sorted[i];
                }

                backet.push_back(strs[ids[i]]);
            }

            if (i == n - 1) {
                ans.push_back(backet);
            }
        }

        return ans;
    }
};

// ["eat","tea","tan","ate","nat","bat"]

// ["aet","aet","ant","aet","ant","abt"]
// [0,1,2,3,4,5]

// ["aet","aet","ant","aet","ant","abt"]
// [0,    1,    2,    3,    4,    5    ]

//  abt   aet   aet   aet   ant   ant 
// [5,    0,    1,    3,    2,    4    ]