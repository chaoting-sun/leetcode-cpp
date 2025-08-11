class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        // is odd -> find (m + n) / 2
        // is even -> find avg((m + n - 1) / 2, (m + n) / 2)
        int is_odd = (m + n) % 2 == 1;
        int target_i = (m + n - 1) / 2, target_j = (m + n) / 2;
        int medium_i = -1, medium_j = -1;

        int count = -1;
        int p1 = -1, p2 = -1, curr = -1;

        while (p1 < m - 1 || p2 < n - 1) {
            if (p1 == m - 1) {
                p2++;
                curr = nums2[p2];
            } else if (p2 == n - 1) {
                p1++;
                curr = nums1[p1];
            } else {
                if (nums1[p1 + 1] < nums2[p2 + 1]) {
                    p1++;
                    curr = nums1[p1];
                } else {
                    p2++;
                    curr = nums2[p2];
                }
            }

            count++;
            if (count == target_i) medium_i = curr;
            if (count == target_j) {
                medium_j = curr;
                break;
            }
        }

        return is_odd ? medium_j : (medium_i + medium_j) / 2.0;

    }
};