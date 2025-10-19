class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> left(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            left[s[i] - 'a']++;
            left[target[i] - 'a']--;
        }

        for (int i = n - 1; i >= 0; i--) {
            left[target[i] - 'a']++;
            
            bool ok = true;
            for (int j = 0; j < 26; j++) {
                if (left[j] < 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (left[j] == 0) {
                    continue;
                }

                target[i] = j + 'a';
                target.resize(i + 1);
                left[j]--;

                for (int j = 0; j < 26; j++) {
                    target += string(left[j], j + 'a');
                }
                return target;
            }
        }
        return "";
    }
};

