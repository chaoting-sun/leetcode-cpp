class Solution {
public:
    // string majorityFrequencyGroup(string s) {
    //     unordered_map<char,int> counts;
    //     for (char c: s) counts[c]++;

    //     unordered_map<int,string> counts_reversed;
    //     string ans = "";
    //     int ansFreq = 0;
    //     for (auto [c, freq]: counts) {
    //         counts_reversed[freq] = c + counts_reversed[freq];
    //         if (counts_reversed[freq].size() > ans.size() || (counts_reversed[freq].size() == ans.size() && freq > ansFreq)) {
    //             ans = counts_reversed[freq];
    //             ansFreq = freq;
    //         }
    //     }
    //     return ans;
    // }

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