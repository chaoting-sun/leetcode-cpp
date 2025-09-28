class Solution {
public:
    // Approach: Hash Table.
    // 1. Count the frequency of each character.
    // 2. Build a mapping: frequency → number of distinct characters with that frequency.
    // 3. Select the frequency with the largest group size; break ties by choosing the larger frequency.
    // 4. Collect all characters that occur with this chosen frequency.
    // Time Complexity: O(n)  (one pass to count + constant 26 letters scanned)
    // Space Complexity: O(1) (fixed alphabet size, extra maps bounded by 26)

    string majorityFrequencyGroup(string s) {
        vector<int> freq(26);
        for (char c: s) freq[c - 'a']++;

        unordered_map<int,int> freqSize;
        for (int f: freq) {
            if (f > 0) freqSize[f]++;
        }

        int bestFreq = 0, bestSize = 0;
        for (auto& [fq, sz]: freqSize) {
            if (sz > bestSize || (sz == bestSize && fq > bestFreq)) {
                bestFreq = fq;
                bestSize = sz;
            }
        }
        
        string group = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] == bestFreq) group.push_back(i + 'a');
        }
        return group;
    }
};