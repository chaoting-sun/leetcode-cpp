class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> distinctCount;
        for (char ch: s) distinctCount[ch]++;
        if (distinctCount.size() <= k) return 0;
        
        vector<int> freq;
        for (auto [ch, f]: distinctCount) freq.push_back(f);
        sort(freq.begin(), freq.end());

        int totalDeleted = 0;
        for (int i = 0; i < freq.size() - k; i++) {
            totalDeleted += freq[i];
        }
        return totalDeleted;
    }
};