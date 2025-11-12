class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<long long, int> prefixCount; // freq of each prefix (key)
        unordered_map<long long, int> prefixAccCount; // accumulated freq of each prefix <= prefix (key)
        long long prefix = 0;
        long long ans = 0;
        prefixCount[0] = 1;
        prefixAccCount[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i] == target ? 1 : -1;
            prefixCount[prefix]++;
            prefixAccCount[prefix] = prefixAccCount[prefix - 1] + prefixCount[prefix];
            ans += prefixAccCount[prefix - 1];
        }
        return ans;
    }
};

// prefix = -1
// prefixCount[-1] = 1
// prefixAccCount[-1] = prefixAccCount[-2] + prefixCount[-1] = prefixAccCount[-2] + 1 = 1

// [0 1 1]

// prefix[j] > prefix[i]
// prefixCount[prefix value] #prefix
// prefixAccCount[prefix value] #<=prefix
// right -> prefix[j], left -> prefixAccCount[prefix[j]-1]
// prefixAccCount[prefix[j]] = prefixAccCount[prefix[j]-1] + prefixCount[prefix value]

// 1 1 1 0 0 1 1 1
// 1 2 3 2 1 2 3 4