class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        unordered_map<int,int> firstIndex, distance, freq;
        int highestFreq = 0, minDistance = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!firstIndex.count(nums[i])) {
                firstIndex[nums[i]] = i;
                distance[nums[i]] = 1;
            } else {
                distance[nums[i]] = i - firstIndex[nums[i]] + 1;
            }
            freq[nums[i]]++;
        }

        for (auto [v, f]: freq) {
            if (f > highestFreq) {
                highestFreq = f;
                minDistance = distance[v];
            } else if (f == highestFreq && distance[v] < minDistance) {
                minDistance = distance[v];
            }
        }

        return minDistance;
    }
};

// [1,2,2,3,1]
// i=0
// firstIndex[1] = 0, distance[1] = 1, freq[1] = 1
// i=1
// firstIndex[2] = 1, distance[2] = 1, freq[2] = 1
// i=2
// distance[2] = 2, freq[2] = 2
// i=3
// firstIndex[3] = 3, distance[3] = 1, freq[3] = 1
// i=4
// distance[1] = 5, freq[1] = 2

// freq = { 1:2, 2:2, 3:1 }
// distance = { 1:5, 2:2, 3:1 }
// v=1, f=2
// highestFreq = 2
// minDistance = 5
// v=2, f=2
// highestFreq = 1
// minDistance = 2
// v=3, f=1

// -> minDistance = 2