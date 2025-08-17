class Solution {
public:
    // Approach1: Brute-force Method (Two Pointers)
    // initiate two pointers p1, p2 at the start of nums1, nums2, comparing them one by one and moving to the medium
    // Time: O(m + n)
    // Space: O(1)

    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int m = nums1.size(), n = nums2.size();

    //     // is odd -> find (m + n) / 2
    //     // is even -> find avg((m + n - 1) / 2, (m + n) / 2)
    //     int is_odd = (m + n) % 2 == 1;
    //     int target_i = (m + n - 1) / 2, target_j = (m + n) / 2;
    //     int medium_i = -1, medium_j = -1;

    //     int count = -1;
    //     int p1 = -1, p2 = -1, curr = -1;

    //     while (p1 < m - 1 || p2 < n - 1) {
    //         if (p1 == m - 1) {
    //             p2++;
    //             curr = nums2[p2];
    //         } else if (p2 == n - 1) {
    //             p1++;
    //             curr = nums1[p1];
    //         } else {
    //             if (nums1[p1 + 1] < nums2[p2 + 1]) {
    //                 p1++;
    //                 curr = nums1[p1];
    //             } else {
    //                 p2++;
    //                 curr = nums2[p2];
    //             }
    //         }

    //         count++;
    //         if (count == target_i) medium_i = curr;
    //         if (count == target_j) {
    //             medium_j = curr;
    //             break;
    //         }
    //     }

    //     return is_odd ? medium_j : (medium_i + medium_j) / 2.0;

    // }

    // Approach2: Binary Search

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // binary search on the smaller array to minimize the search space
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l1 = 0, r1 = n1;
        int c1_left_val, c1_right_val, c2_left_val, c2_right_val;

        while (l1 <= r1) {
            int mid1 = (l1 + r1) / 2;
            int mid2 = (n1 + n2 + 1) / 2 - mid1;
            
            c1_left_val = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            c1_right_val = mid1 == n1 ? INT_MAX : nums1[mid1];
            c2_left_val = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            c2_right_val = mid2 == n2 ? INT_MAX : nums2[mid2];

            // termination condition
            if (c1_left_val <= c2_right_val && c2_left_val <= c1_right_val) {
                break;
            } else if (c1_left_val > c2_right_val) {
                r1 = mid1;
            } else {
                l1 = mid1 + 1;
            }
        }

        // even
        if ((n1 + n2) % 2 == 0) {
            return (max(c1_left_val, c2_left_val) + min(c1_right_val, c2_right_val)) / 2.0;
        }
        // odd
        else {
            return max(c1_left_val, c2_left_val);
        }
    }
};