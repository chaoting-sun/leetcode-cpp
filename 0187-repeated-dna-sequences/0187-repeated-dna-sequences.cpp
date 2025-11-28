// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         int n = s.size();
//         if (n <= 10) return {};
        
//         unordered_set<string> visited;
//         unordered_set<string> visitedAgain;
//         string current = s.substr(0, 10);
//         visited.insert(current);

//         for (int i = 10; i < n; i++) {
//             string temp = current.substr(1);
//             temp.push_back(s[i]);
//             if (visited.count(temp)) {
//                 visitedAgain.insert(temp);
//             }
//             visited.insert(temp);
//             current = temp;
//         }
//         vector<string> ans;
//         for (const string& seq: visitedAgain) {
//             ans.push_back(seq);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n <= 10) return {};
        
        unordered_set<int> visited;
        unordered_set<string> visitedAgain;
        int current = 0;
        int mask = (1 << 20) - 1;

        vector<int> toInt(26);
        toInt['A' - 'A'] = 0;
        toInt['T' - 'A'] = 1;
        toInt['C' - 'A'] = 2;
        toInt['G' - 'A'] = 3;

        for (int i = 0; i < n; i++) {
            current <<= 2;
            current |= toInt[s[i] - 'A'];
            current &= mask;
            if (i < 9) continue;

            if (visited.count(current)) {
                visitedAgain.insert(s.substr(i - 9, 10));
            }
            visited.insert(current);
        }

        vector<string> ans;
        for (const string& seq: visitedAgain) {
            ans.push_back(seq);
        }
        return ans;
    }
};