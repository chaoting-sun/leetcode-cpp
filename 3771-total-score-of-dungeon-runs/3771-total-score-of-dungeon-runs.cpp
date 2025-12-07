class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();

        vector<long long> prefix_damage(n + 1);
        for (int i = 0; i < n; i++) {
            prefix_damage[i + 1] = prefix_damage[i] + damage[i];
        }

        long long num_points = 0;

        for (int i = 1; i <= n; i++) {
            // find the first j in prefix_damage such that hp - (prefix_damage[i] - prefix_damage[j]) >= requirement[i]
            // It means: prefix_damage[j] >= prefix_damage[i] + requirement[i] - hp;
            long long target = (long long)prefix_damage[i] + requirement[i - 1] - hp;
            auto first_index_it = lower_bound(prefix_damage.begin(), prefix_damage.begin() + i, target);

            num_points += (prefix_damage.begin() + i) - first_index_it;
        }

        return num_points;
    }
};

// class Solution {
// public:
//     long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
//         int n = damage.size();
//         vector<long long> suffixDamage(n);
//         suffixDamage[n - 1] = damage[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             suffixDamage[i] = suffixDamage[i + 1] + damage[i];
//         }

//         long long ans = 0;
//         int shift = 0;
        
//         for (int i = n - 1; i >= 0; i--) {
//             int left = 0, right = i + 1;
//             while (left < right) {
//                 int mid = left + (right - left) / 2;
//                 if (suffixDamage[mid] - shift + requirement[i] <= hp) {
//                     right = mid;
//                 } else {
//                     left = mid + 1;
//                 }
//             }

//             if (right <= i) ans += i - right + 1;
//             shift += damage[i];
//         }
//         return ans;
//     }
// };

