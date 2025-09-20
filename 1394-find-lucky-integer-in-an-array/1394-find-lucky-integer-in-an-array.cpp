class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> valueCount;
        for (int val: arr) valueCount[val]++;
        int largestLucky = -1;
        for (auto [value, count]: valueCount) {
            if (value == count && value > largestLucky) {
                largestLucky = value;
            }
        }
        return largestLucky;
    }
};