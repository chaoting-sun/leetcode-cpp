class Solution {
public:
    int getMinSwaps(string num, int k) {
        string num0(num);
        for (int i = 0; i < k; i++) {
            next_permutation(num.begin(), num.end());
        }

        // num0 -> num
        int ans = 0;
        int n = num.size();
        // 遍歷 num
        for (int i = 0; i < n; i++) {
            int count = 0;
            // 遍歷 num0
            for (int j = 0; j < n; j++) {
                if (num0[j] == '#') continue;
                if (num0[j] == num[i]) {
                    ans += count;
                    num0[j] = '#';
                    break;
                }
                count++;
            }
        }
        return ans;
    }
};


// 21435
// 12345